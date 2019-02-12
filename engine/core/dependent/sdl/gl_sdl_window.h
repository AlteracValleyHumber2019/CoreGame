#ifndef GL_SDL_WINDOW_H
#define GL_SDL_WINDOW_H

#include "../../i_window.h"

#include <SDL/SDL.h>

namespace pav
{
	/**
	 * \class	GLSDLWindow
	 *
	 * \brief	An OpenGL-SDL window
	 *
	 * \author	Jaymie
	 * \date	2/12/2019
	 */
	class GLSDLWindow : public pav::IWindow
	{
	private:
		std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;
		SDL_GLContext main_context_;

	public:
		explicit GLSDLWindow();

		void CreateWindow(pav::WindowInfo&& win_info) override;
		void DestroyWindow() override;
		void SetAsContext() override;
		void Update(const float delta_time) override;
	};
}

#endif // GL_SDL_WINDOW_H
