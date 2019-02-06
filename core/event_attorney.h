#ifndef EVENT_ATTORNEY_H
#define EVENT_ATTORNEY_H

namespace pav
{
	/**
	 * \struct	EventAttorney
	 *
	 * \brief	An event attorney class used to hide certain implementation details for event manager
	 *
	 * \author	Jaymie
	 * \date	2/6/2019
	 */
	struct EventAttorney
	{
		/** \brief	A pointer to a Signal for all input events, this include keyboard input and mouse input */
		Signal<void, InputEventType>* on_input;
		/** \brief	A pointer to a Signal for a keyboard down event */
		Signal<void, KeyCode>* on_key_down;
		/** \brief	A pointer to a Signal for a keyboard hold event */
		Signal<void, KeyCode>* on_key_hold;
		/** \brief	A pointer to a Signal for a keyboard up event */
		Signal<void, KeyCode>* on_key_up;
		/** \brief	A pointer to a Signal for a mouse button down event */
		Signal<void, MouseButtonCode, unsigned short>* on_mouse_button_down;
		/** \brief	A pointer to a Signal for a mouse button up event */
		Signal<void, MouseButtonCode, unsigned short>* on_mouse_button_up;
	};
}

#endif // EVENT_ATTORNEY_h
