#include "pav_pch.h"
#include "gl_sdl_render_manager.h"

#include <SDL/SDL.h>
#include <glad/glad.h>

pav::IRenderer* pav::GLSDLRenderManager::CreateRenderer()
{
	return nullptr;
}

void pav::GLSDLRenderManager::Initialize()
{
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		// TODO: Invoke assert
		printf(SDL_GetError());
		return;
	}

	// OpenGL 4.0
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// Set to core profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Enable double buffer
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);  // Enable 32bit z buffer

	// Down here
}

void pav::GLSDLRenderManager::End()
{
	SDL_Quit();
}

void pav::GLSDLRenderManager::Update(const float delta_time)
{
}
