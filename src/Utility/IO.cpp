#include "IO.h"

namespace crynn
{
	void drop_callback(GLFWwindow* window, int count, const char** paths)
	{
		for (int i = 0; i < count; i++)
		{
#ifdef CRYNN_DEBUG
			std::cout << "Dispatching File Drop For Path: " << paths[i] << "\n";
#endif
			IO::OnFileDrop.Invoke(paths[i]);
		}
	}

	void IO::Init()
	{
		glfwSetDropCallback(Window::GetCurrentWindow()->GetGLFWWindow(), drop_callback);
		Debug::Log("IO Initialised");
	}

	bool IO::FileExists(const char* relativePath)
	{
		return std::filesystem::exists(relativePath);
	}

	//Allows user to choose an image and returns the filepath after selection.
	std::string IO::OpenImageFilePicker()
	{
		std::string filePath = "";

		HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

		if (SUCCEEDED(hr))
		{
			IFileOpenDialog* pFileOpen;

			// Create the FileOpenDialog object.
			hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
				IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

			/* Set file types */
			COMDLG_FILTERSPEC fileTypes[] =
			{
				{ L"Supported Image Files", L"*.png;*.jpg;*.jpeg;"},
			};

			pFileOpen->SetFileTypes(ARRAYSIZE(fileTypes), fileTypes);
			pFileOpen->SetDefaultExtension(L"jpg");

			if (SUCCEEDED(hr))
			{
				// Show the Open dialog box.
				hr = pFileOpen->Show(NULL);

				// Get the file name from the dialog box.
				if (SUCCEEDED(hr))
				{
					IShellItem* pItem;
					hr = pFileOpen->GetResult(&pItem);
					if (SUCCEEDED(hr))
					{
						PWSTR pszFilePath;
						hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

						// Display the file name to the user.
						if (SUCCEEDED(hr))
						{
							//Convert from wide string to const char*.
							//wcslen gets wide string length
							//Convert the string:

							//Create a buffer to hold it. Add one for null term char.
							std::unique_ptr<char[]> buf = std::make_unique<char[]>(wcslen(pszFilePath) + 1);

							size_t retVal = 0; //Windows needs this for some reason ):
							wcstombs_s(&retVal, buf.get(), wcslen(pszFilePath) + 1, pszFilePath, _TRUNCATE); //Copy the data into buf

							filePath = buf.get(); //Update filePath
							CoTaskMemFree(pszFilePath);
						}
						pItem->Release();
					}
				}
				pFileOpen->Release();
			}
			CoUninitialize();
		}
		return filePath; //Create a GetFileArgs object and return it.
	}

	std::string IO::LoadFileStr(const char* relativePath)
	{
		std::string str; //declare here to enable RVO

		//Error check
		if (!FileExists(relativePath))
		{
			std::cerr << "Tried loading file that does not exist: " << relativePath << "\n";
			return "";
		}
		
		//Create stream
		std::ifstream t(relativePath);

		//This looks funky but its just constructing an std::string with a streambuf iterator in the file
		str = std::string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());

		return str;
	}

	bool IO::AddMediaPath(const char* pathStr)
	{
		fs::path path = fs::current_path() /= (pathStr);

		if (fs::exists(path))
		{
			mediaPaths.push_back(pathStr);
			return true;
		}
		else
			return false;
	}

	/*
	GetFileData IO::GetMediaFile(const char* name)
	{
		GetFileData data;

		try
		{
			for (fs::path mediaPath : mediaPaths)
			{
				std::cout << "Looking in Media Path: " << mediaPath.string() << "\n";

				//loop through files in media paths
				for (auto& filePath : fs::directory_iterator(mediaPath))
				{
					//create a path relative to the media path for easy comparison
					fs::path relativeFilePath = fs::relative(filePath, mediaPath);

					//If we found the file, create an absolute path and use that.
					if (relativeFilePath.string() == name)
					{
						data.succeeded = true;
						data.absoluteFilePath = fs::absolute(relativeFilePath).string();
						break;
					}
				}

			}
		}
		catch(std::exception e) 
		{
			std::cout << "Error Occured Searching For File: " << e.what() << "\n";
		}

		if (data.succeeded)
			std::cout << "File found at: " << data.absoluteFilePath << "\n";
		else
			std::cout << "File: " << name << " not found in media paths\n";

		return data;
	}
	*/
}