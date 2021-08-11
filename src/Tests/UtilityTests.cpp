#include "pch.h"
#include "CppUnitTest.h"
#include "../Core/Math/Math.h"
#include <string_view>

#pragma warning( disable : 4244)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace crynn;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> inline std::wstring ToString<Vec3>(const Vec3& t)
			{
				std::wstring vec;

				vec += t.x;
				vec += L" ";
				vec += t.y;
				vec += L" ";
				vec += t.z;

				return vec;
			}

			template<> inline std::wstring ToString<Vec2>(const Vec2& t)
			{
				std::wstring vec;

				vec += t.x;
				vec += L" ";
				vec += t.y;

				return vec;
			}
		}
	}
}

