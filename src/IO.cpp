#include "IO.h"

//Allows user to choose an image and returns the filepath after selection.
std::string File::GetFile()
{
	std::string filePath;

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
		COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileOpenDialog *pFileOpen;

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
				IShellItem *pItem;
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

						//Setup logging
						std::ofstream log;
						log.open("output.log");
						if (log.is_open())
							log << "Size of file path: " << *pszFilePath << std::endl;

						//Convert the string:

						//Create a buffer to hold it. Add one for null term char.
						std::unique_ptr<char[]> buf = std::make_unique<char[]>(wcslen(pszFilePath) + 1);

						size_t retVal = 0; //Windows needs this for some reason ):
						wcstombs_s(&retVal, buf.get(), wcslen(pszFilePath) + 1, pszFilePath, _TRUNCATE); //Copy the data into buf

						filePath = buf.get(); //Update filePath

						//Finalize resources
						log << filePath.c_str() << std::endl;
						log.close();
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();
				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}
	return filePath;

}