#ifndef GL_SDL_RENDER_MANAGER_H
#define GL_SDL_RENDER_MANAGER_H
#include "pav_pch.h"
#include "../../render_manager.h"

namespace pav
{
	/**
	 * \class	GLSDLRenderManager
	 *
	 * \brief	Manager class for OpenGL SDL renderer
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class GLSDLRenderManager : public RenderManager
	{
	public:
		IRenderer* CreateRenderer() override;
		void Initialize() override;
		void End() override;
		void Update(const float delta_time) override;

		// timing
		float deltaTime = 0.0f;
		float lastFrame = 0.0f;
	};
}

#endif // GL_SDL_RENDER_MANAGER_H
