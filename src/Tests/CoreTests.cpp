#include "pch.h"
#include "CppUnitTest.h"
#include "../Core/Math/Math.h"
#include "../Core/Math/Math.cpp"
#include "../Core/Transform.cpp"
#include "GLFW/glfw3.h"
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


			//Compares transform identity
			template<> inline std::wstring ToString<Transform>(const Transform& t)
			{
				intptr_t ptr = (intptr_t)&t;

				std::wstring str = std::to_wstring(ptr);

				return str;
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

		TEST_METHOD(fApproxEqualTest) 
		{
			float n = 5.0f / 162.0f;
			float y = 5.0f / 162.0f;

			Assert::IsTrue(Math::fApproxEqual(n, y));
		}

		TEST_METHOD(NormalizeAngleTestPositive) 
		{
			float theta = 380.0f;
			float result = Math::NormalizeAngle(theta);

			Assert::IsTrue(Math::fApproxEqual(result, 20.0f));
		}

		TEST_METHOD(NormalizeAngleTestNegative)
		{
			float theta = -20.0f;
			float result = Math::NormalizeAngle(theta);

			Assert::IsTrue(Math::fApproxEqual(result, 340.0f));
		}

		TEST_METHOD(Vec3ApproxEqualTest) 
		{
			//Give each component long floating point numbers that can cause floating p errors
			const Vec3 one = Vec3(5.0f) / 162.0f;
			const Vec3 two = Vec3(5.0f) / 162.0f;

			Assert::IsTrue(Math::Vec3ApproxEqual(one, two));
		}

		TEST_METHOD(Vec3ApproxEqualTestNegative)
		{
			//Give each component long floating point numbers that can cause floating p errors
			const Vec3 one = Vec3(5.0f) / 162.0f;
			const Vec3 two = Vec3(-5.0f) / 162.0f;

			Assert::IsFalse(Math::Vec3ApproxEqual(one, two));
		}

		TEST_METHOD(Vec2ApproxEqualTest) 
		{
			//Give each component long floating point numbers that can cause floating p errors
			const Vec2 one = Vec2(5.0f) / 162.0f;
			const Vec2 two = Vec2(5.0f) / 162.0f;

			Assert::IsTrue(Math::Vec2ApproxEqual(one, two));
		}
	};
	
	TEST_CLASS(TransformTest) 
	{
	public:

		TEST_METHOD(SetParentTest) 
		{
			Transform tr;
			Transform tr2;

			tr.SetParent(&tr2);
			
			Assert::AreSame(tr.GetParent(), tr2);
		}
/*
		TEST_METHOD(SetParentReassignment) 
		{
			Transform tr1;
			Transform tr2;

			tr1.SetParent(&tr2);
			Assert::AreSame(tr1.GetParent(), tr2);

			//switch the parents
			tr2.SetParent(&tr1);
			Assert::AreSame(tr2.GetParent(), tr1);

			//Make sure that tr1 is no longer a child of tr2
			//Edge case where you setparent of tr1 to tr2, and then setparent of tr2 to tr1.
			bool containsTr1 = tr2.GetChildren().find(&tr1) != tr2.GetChildren().end();

			Assert::IsFalse(containsTr1);
		}

		TEST_METHOD(RemoveParentTest) 
		{
			Transform tr1;
			Transform tr2;

			tr2.SetParent(&tr1);
			tr2.RemoveParent();


			bool containsTr1 = tr2.GetChildren().find(&tr1) != tr2.GetChildren().end();

			Assert::IsFalse(containsTr1);
		}

		TEST_METHOD(TransformNullptrTests) 
		{
			bool threwException = false;
			try 
			{
				Transform tr1;
				Transform tr2;

				tr2.SetParent(nullptr);


				bool containsTr1 = tr2.GetChildren().find(&tr1) != tr2.GetChildren().end();

				Assert::IsFalse(containsTr1);
			}
			catch(...) 
			{
				threwException = true;
			}

			Assert::IsFalse(threwException);
		}
			*/
	};
}
