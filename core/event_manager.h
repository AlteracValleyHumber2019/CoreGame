#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "i_manager.h"
#include "event_util.h"

namespace pav
{
	/**
	 * \class	EventManager
	 *
	 * \brief	Manager class for events.
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class EventManager : public IManager
	{
	public:
		/** \brief	Signal for all input events, this include keyboard input and mouse input */
		Signal<InputEventType> on_input;
		/** \brief	Signal for a keyboard down event */
		Signal<KeyCode> on_key_down;
		/** \brief	Signal for a keyboard hold event */
		Signal<KeyCode> on_key_hold;
		/** \brief	Signal for a keyboard up event */
		Signal<KeyCode> on_key_up;

		void Update(const float delta_time) override;
	};
}

#endif // EVENT_MANAGER_H
