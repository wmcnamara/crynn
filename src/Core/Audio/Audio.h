#pragma once
#include "al.h"
#include "alc.h"
#include <iostream>
#include <assert.h>

#include "AudioBuffer.h"

namespace Crynn 
{
	class Audio
	{
	public:
		static bool Initialize();
		static bool Uninitialize();
	};
}