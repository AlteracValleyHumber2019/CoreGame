#include "pav_pch.h"
#include "sdl_event_manager.h"

#include <SDL/SDL.h>

void pav::SDLEventManager::Initialize()
{
	
}

void pav::SDLEventManager::End()
{
}

void pav::SDLEventManager::Update(const float delta_time)
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
	}
}
