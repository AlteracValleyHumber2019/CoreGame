#include "pav_pch.h"
#include "gl_sdl_render_manager.h"
#include "glfw\glfw3.h"
#include <glm/gtc/type_ptr.hpp>
#include <SDL/SDL.h>
#include "imgui_impl_opengl3.h"
#include "core\SDLCamera.h"

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
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);

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
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

void pav::GLSDLRenderManager::End()
{
	SDL_Quit();
}

void pav::GLSDLRenderManager::Update(const float delta_time)
{
	/* Needs to be properly Implemented [BP]
		// render
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDLCamera camera = SDLCamera(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f);
		// view/projection transformations
		glm::mat4 projection = glm::perspective(glm::radians(camera.zoom), (float)800 / (float)600, 0.1f, 100.0f);
		glm::mat4 view = camera.getViewMatrix();

		// render the loaded model
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down*/
}
