#include "pav_pch.h"
#include "gl_sdl_window.h"

pav::GLSDLWindow::GLSDLWindow() :
window_(nullptr, SDL_DestroyWindow)
{
}

void pav::GLSDLWindow::MakeWindow(pav::WindowInfo&& win_info)
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

	window_ptr_ = window_.get();
}

WindowType* pav::GLSDLWindow::GetWindow()
{
	return window_ptr_;
}

void pav::GLSDLWindow::DestroyWindow()
{
	window_.release();
	window_.reset(nullptr);
}

void pav::GLSDLWindow::SetAsContext()
{
	main_context_ = SDL_GL_CreateContext(window_.get());

	// This initializes GLAD with SDL - Gabriel Kalil
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		printf("%s \n", "Failed to initialize GLAD");
		return;
	}

	glEnable(GL_DEPTH_TEST);
}

void pav::GLSDLWindow::Update(const float delta_time, SceneManager* manager)
{
	SDL_GL_MakeCurrent(window_.get(), main_context_);

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	manager->GetCurrentScene()->Update(delta_time);

	SDL_GL_SwapWindow(window_.get());
}
