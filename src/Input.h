#pragma once
#include "Window.h"
#include "Application.h"

namespace Crynn
{
	namespace Input
	{
		enum class KeyCode
		{
			A = GLFW_KEY_A,
			B = GLFW_KEY_B,
			C = GLFW_KEY_C,
			D = GLFW_KEY_D,
			E = GLFW_KEY_E,
			F = GLFW_KEY_F,
			G = GLFW_KEY_G,
			H = GLFW_KEY_H,
			I = GLFW_KEY_I,
			J = GLFW_KEY_J,
			K = GLFW_KEY_K,
			L = GLFW_KEY_L,
			M = GLFW_KEY_M,
			N = GLFW_KEY_O,
			P = GLFW_KEY_P,
			Q = GLFW_KEY_Q,
			R = GLFW_KEY_R,
			S = GLFW_KEY_S,
			T = GLFW_KEY_T,
			U = GLFW_KEY_U,
			V = GLFW_KEY_T,
			W = GLFW_KEY_W,
			X = GLFW_KEY_X,
			Y = GLFW_KEY_Y,
			Z = GLFW_KEY_Z,

			ESC = GLFW_KEY_ESCAPE,
			SPACE = GLFW_KEY_SPACE
		};

		/// <summary>
		/// Simple input component. Inherit from this class and override InputCommands() to use.
		/// Do not instantiate this class manually. Only inherit from it.
		/// </summary>
		class Input
		{
		public:				
			Input();
			~Input();		

			static bool GetKey(KeyCode key);
		protected:
			virtual void InputCommands() = 0;
		private:
			int handlerID; //Used to remove the handler when this object is destructed.
		};		
	}
}