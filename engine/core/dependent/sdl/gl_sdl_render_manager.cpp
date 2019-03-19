#include "pav_pch.h"
#include "gl_sdl_render_manager.h"

#include <SDL/SDL.h>
#include <glad/glad.h>
#include "imgui_impl_opengl3.h"

pav::IRenderer* pav::GLSDLRenderManager::CreateRenderer()
{
	return nullptr;
}

void pav::GLSDLRenderManager::Initialize()
{
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		PAV_ASSERT(false, SDL_GetError());
	}

	int res = 0;

	res = SDL_GL_LoadLibrary(NULL);
	PAV_ASSERT(res == 0, "Could not set OpenGL Libary");

	// OpenGL 4.3
	res = SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	PAV_ASSERT(res == 0, "Error");

	res = SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	PAV_ASSERT(res == 0, "Error");

	res = SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	PAV_ASSERT(res == 0, "Error");

	// Set to core profile
	res = SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	PAV_ASSERT(res == 0, "Error");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // Enable double buffer
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);  // Enable 24bit z buffer
}

void pav::GLSDLRenderManager::End()
{
	SDL_Quit();
}

void pav::GLSDLRenderManager::Update(const float delta_time)
{
}
