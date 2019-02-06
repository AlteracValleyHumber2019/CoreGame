#ifndef SDL_EVENT_MANAGER_H
#define SDL_EVENT_MANAGER_H

#include "../../event_manager.h"

#include <SDL/SDL.h>

namespace pav
{
	class SDLEventManager : public EventManager
	{
	private:
		std::unordered_map<SDL_Keycode, KeyCode> sdl_key_map_;

	public:
		void Initialize() override;
		void End() override;
		void Update(const float delta_time) override;
	};
}
#endif // SDL_EVENT_MANAGER_H
