#ifndef SDL_EVENT_MANAGER_H
#define SDL_EVENT_MANAGER_H

#include "../../event_manager.h"

namespace pav
{
	class SDLEventManager : public EventManager
	{
	public:
		void Initialize() override;
		void End() override;
		void Update(const float delta_time) override;
	};
}
#endif // SDL_EVENT_MANAGER_H
