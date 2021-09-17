#pragma once
#include <GLFW/glfw3.h>
#include "Event.h"
#include "Math/Math.h"

#define KEYSTATE_BUFFER_MAX_SIZE 350

namespace crynn
{
	enum class KeyCode; //forward declare

	/*
		The input component provides access to input data like key states, mouse deltas and scroll deltas.
	*/
	class InputComponent
	{
	public:
		//Allocates buffers for keystates, and sets up events.
		InputComponent();
		~InputComponent();

		//Call after glfwPollevents, and before accepting input.
		void PollInput() const;

		/// <summary>
		/// Returns the state of a key.
		/// </summary>
		/// <param name="key">KeyCode of the key you would like the state of</param>
		/// <returns>True if the key is pressed</returns>
		bool GetKey(KeyCode key) const;

		/// <summary>
		/// Returns the state of a key once per press, in a toggle style.
		/// </summary>
		/// <param name="key">KeyCode of the key you would like the state of</param>
		/// <returns>True if the key has been toggled.</returns>
		bool GetKeyDown(KeyCode key) const;

		//Internally sets the mouse position for tracking
		//Only call if you really know what you're doing.
		void UpdateMousePosInternal();
		
		//Returns a Vector2 representing the difference in mouse position from the previous frame.
		//In screen coordinates.
		Vec2 GetMouseDelta() const;

		//Returns a Vec2 with the current xy coordinate of the mouse in screen space.
		Vec2Int GetMousePosition();

		//Locks the mouse to the center of the screen, hides it and allows movement.
		void LockMouse() const;

		//Allows the mouse to move freely.
		void UnlockMouse() const;

		//Dispatched when the user scrolls the mouse wheel.
		inline static Event<float> OnMouseScroll;

	private:
		InputComponent(InputComponent&& other) = delete;
		InputComponent operator=(InputComponent&& other) = delete;

		InputComponent(const InputComponent& other) = delete;
		InputComponent operator=(const InputComponent& other) = delete;

		void UpdateKeyboardState(GLFWwindow* window, int key, int scancode, int action, int mods);
		void UpdateMouseState(double yoffset);

		//glfw friend function callbacks
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

		std::unique_ptr<bool[]> m_currentKeyStatesBuffer; //The states of each key in the current frame.
		std::unique_ptr<bool[]> m_getKeyDownStatesBuffer; //The states of each key for GetKeyDown.

		double m_xPos = 0; //Current x pixel coordinate position of the cursor
		double m_prevXPos = 0; //x pixel coordinate position of the cursor in the previous frame
		
		double m_yPos = 0; //Current y pixel coordinate position of the cursor
		double m_prevYPos = 0; //y pixel coordinate position of the cursor in the previous frame
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
		ENTER = GLFW_KEY_ENTER,
		LSHIFT = GLFW_KEY_LEFT_SHIFT
	};
}