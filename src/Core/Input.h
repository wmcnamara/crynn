#pragma once
#include <GLFW/glfw3.h>
#include "Math/Math.h"
#include "Event.h"

#define KEYSTATE_BUFFER_MAX_SIZE 350

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

		//Call after glfwPollevents, and before accepting input.
		static void StartPoll();

		/// <summary>
		/// Returns the state of a key.
		/// </summary>
		/// <param name="key">KeyCode of the key you would like the state of</param>
		/// <returns>True if the key is pressed</returns>
		static bool GetKey(KeyCode key);

		/// <summary>
		/// Returns the state of a key once per press, in a toggle style.
		/// </summary>
		/// <param name="key">KeyCode of the key you would like the state of</param>
		/// <returns>True if the key has been toggled.</returns>
		static bool GetKeyDown(KeyCode key);

		//Internally sets the mouse position for tracking
		//Only call if you really know what you're doing.
		static void UpdateMousePosInternal();
		
		//Returns a Vector2 representing the difference in mouse position from the previous frame.
		//In screen coordinates.
		static Vec2 GetMouseDelta();

		//Returns a Vec2 with the current xy coordinate of the mouse in screen space.
		static Vec2Int GetMousePosition();

		//Locks the mouse to the center of the screen, hides it and allows movement.
		static void LockMouse();

		//Allows the mouse to move freely.
		static void UnlockMouse();

		//Dispatched when the user scrolls the mouse wheel.
		inline static Event<float> OnMouseScroll;

	private:
		//glfw friend function callbacks
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

		inline static bool currentKeyStates[KEYSTATE_BUFFER_MAX_SIZE]; //The states of each key in the current frame.
		inline static bool getKeyDownStates[KEYSTATE_BUFFER_MAX_SIZE]; //The states of each key for GetKeyDown.

		inline static std::atomic_bool m_initialised = false; //Is input initialised?

		inline static double m_xPos = 0; //Current x pixel coordinate position of the cursor
		inline static double m_prevXPos = 0; //x pixel coordinate position of the cursor in the previous frame
					  
		inline static double m_yPos = 0; //Current y pixel coordinate position of the cursor
		inline static double m_prevYPos = 0; //y pixel coordinate position of the cursor in the previous frame
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