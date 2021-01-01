#pragma once
#include "Window.h"

namespace crynn
{
	enum class KeyCode; //forward declare
	/// <summary>
	/// Simple input component that allows interfacing with the Crynn input system.
	/// </summary>
	class Input
	{
	public:
		//Initialises input, and sets up polling events.
		static void Init();

		/// <summary>
		/// Returns the state of a key.
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		static bool GetKey(KeyCode key);

		/// <summary>
		/// Returns the state of a key once per press, in a toggle style.
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		static bool GetKeyDown(KeyCode key);

		inline static void UpdateKeyState(int key, bool state)
		{
			states[key] = state;
		}
	private:
		inline static bool states[348]; //Unfortunately most of this is wasted because of how glfw chooses to handle input keycodes.
		inline static bool m_initialised = false;
		int handlerID; //Used to remove the handler when this object is destructed.
	};

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
}