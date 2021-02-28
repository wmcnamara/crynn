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

		/// <summary>
		/// Used in GLFW events to update the keystate of a key in the current frame. This function should only be ever used in GLFW events, or internal input function
		/// </summary>
		/// <param name="key">The GLFW keycode of the key you're updating</param>
		/// <param name="state">The boolean state of the key</param>
		inline static void UpdateKeyStateInternal (int key, bool state)
		{
			previousKeyStates[key] = currentKeyStates[key]; //Update previous keystate
			currentKeyStates[key] = state; //Update current keystate
		}

		static void UpdateMousePosInternal(int xPos, int yPos);

		static Vec2Int GetMouseDelta() 
		{ 
			return Vec2Int
			(
				m_xPos - m_prevXPos, 
				m_yPos - m_prevYPos
			); 
		}

		//Dispatched when the user scrolls the mouse wheel.
		inline static Event<float> OnMouseScroll;
	private:
		inline static bool currentKeyStates[349]; //The states of each key in the current frame.
		inline static bool previousKeyStates[349]; //The states of each key from the previous frame. Needed for GetKeyDown

		inline static bool m_initialised = false; //Is input initialised?

		inline static int m_xPos = 0; //Current x pixel coordinate position of the cursor
		inline static int m_prevXPos = 0; //x pixel coordinate position of the cursor in the previous frame

		inline static int m_yPos = 0; //Current y pixel coordinate position of the cursor
		inline static int m_prevYPos = 0; //y pixel coordinate position of the cursor in the previous frame
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
		SPACE = GLFW_KEY_SPACE,
		ENTER = GLFW_KEY_ENTER
	};
}