#include "pch.h"
#include "CppUnitTest.h"
#include "../Core/Math/Math.cpp"
#include "../Core/Transform.h"

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

namespace CrynnTests
{
	TEST_CLASS(MathTest)
	{
	public:

		TEST_METHOD(ParseVec3Test) 
		{
			const char* sampleText = "-1.0 1.0 -1.0";
			Vec3 vec = ParseVec3(sampleText);
			Assert::AreEqual(vec, Vec3(-1.0, 1.0, -1.0));
		}

		TEST_METHOD(ParseVec2Test) 
		{
			const char* sampleText = "-1.0 1.0";
			Vec2 vec = ParseVec3(sampleText);
			Assert::AreEqual(vec, Vec2(-1.0, 1.0));
		}
	};

	TEST_CLASS(TransformTest) 
	{
	public:

		TEST_METHOD(SetParentTestBase) 
		{
			Transform tr;
			Transform tr2;

			tr.SetParent(&tr2);
			Assert::AreEqual(tr.GetParent(), &tr2);		
		}
	};
}
