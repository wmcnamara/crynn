#pragma once
#include "Window.h"
#include "Application.h"

namespace Crynn
{
	/// <summary>
	/// Simple input component that allows interfacing with the Crynn input system.
	/// Inherit from this class and override InputCommands() to use.
	/// </summary>
	class Input
	{
	public:
		Input();
		~Input();

		/// <summary>
		/// Keycodes for input commands.
		/// </summary>
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
		/// Returns the state of 
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		static bool GetKey(KeyCode key);
	protected:
		/// <summary>
		/// Called every frame when polling events.
		/// Override this and add code that checks input.
		/// </summary>
		virtual void InputCommands() = 0;
	private:
		int handlerID; //Used to remove the handler when this object is destructed.
	};
}