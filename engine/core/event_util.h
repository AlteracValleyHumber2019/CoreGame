#ifndef EVENT_UTIL_H
#define EVENT_UTIL_H

namespace pav
{
	/**
	 * \enum	InputEventType
	 *
	 * \brief	Values that represent input event types
	 */
	enum InputEventType
	{
		DOWN,
		UP,
		HOLD
	};

	/**
	 * \enum	MouseButtonCode
	 *
	 * \brief	Values that represent mouse buttons
	 */
	enum MouseButtonCode
	{
		LEFT,
		RIGHT,
		MIDDLE
	};

	/**
	 * \enum	KeyCode
	 *
	 * \brief	Values that represent keys on a standard keyboard
	 */
	enum KeyCode
	{
		KEY_A,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z
	};
}

#endif // EVENT_UTIL_H
