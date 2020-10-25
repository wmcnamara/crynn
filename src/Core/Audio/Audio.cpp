#include "Audio.h"
namespace Crynn
{
	bool Audio::Initialize()
	{
		static bool initialized = false; //use to prevent double initialization
		assert(!initialized);

		ALCdevice* device = alcOpenDevice(NULL);

		if (!device)
		{
			std::cerr << "OpenAL initialization failed!\n";
			return 0;
		}

		ALCcontext* Context = alcCreateContext(device, 0);
		alcMakeContextCurrent(Context);

		bool g_bEAX = alIsExtensionPresent("EAX2.0");
		alGetError(); //Clear error code
	}

	bool Audio::Uninitialize()
	{
		return false;
	}
}