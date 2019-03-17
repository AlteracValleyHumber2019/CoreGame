#include "pav_pch.h"
#include "gl_sdl_window.h"
#include "glad/glad.h"

pav::GLSDLWindow::GLSDLWindow() :
window_(nullptr, SDL_DestroyWindow)
{
}

void pav::GLSDLWindow::CreateWindow(pav::WindowInfo&& win_info)
{
	window_.reset
	(
		SDL_CreateWindow
		(
			win_info.title.c_str(),
			win_info.pos_x,
			win_info.pos_y,
			win_info.width,
			win_info.height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
		)
	);
}

void pav::GLSDLWindow::DestroyWindow()
{
	window_.release();
	window_.reset(nullptr);
}

void pav::GLSDLWindow::SetAsContext()
{
	main_context_ = SDL_GL_CreateContext(window_.get());

	// INIT GLAD
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		printf("%s \n", "Failed to initialize GLAD");
		return;
	}
}

void pav::GLSDLWindow::Update(const float delta_time)
{
}
