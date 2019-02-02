#include "pav_pch.h"
#include "sdl_event_manager.h"

#include <SDL/SDL.h>

void pav::SDLEventManager::Initialize()
{
	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		// TODO: Invoke assert
		return;
	}
}

void pav::SDLEventManager::End()
{
	SDL_Quit();
}
