#include "pav_pch.h"
#include "gl_sdl_window.h"

GLSDLWindow::GLSDLWindow() :
window_(nullptr, SDL_DestroyWindow)
{
}

void GLSDLWindow::CreateWindow(pav::WindowInfo&& win_info)
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

void GLSDLWindow::DestroyWindow()
{
	window_.release();
	window_.reset(nullptr);
}

void GLSDLWindow::SetAsContext()
{
	main_context_ = SDL_GL_CreateContext(window_.get());
}

void GLSDLWindow::Update(const float delta_time)
{
}
