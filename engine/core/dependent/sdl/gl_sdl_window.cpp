#include "pav_pch.h"
#include "gl_sdl_window.h"

#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

pav::GLSDLWindow::GLSDLWindow() :
window_(nullptr, SDL_DestroyWindow),
io()
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

	// IMGUI
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplSDL2_InitForOpenGL(window_.get(), main_context_);
	ImGui_ImplOpenGL3_Init("#version 430 core");
}

void pav::GLSDLWindow::Update(const float delta_time)
{
	ImGui::Render();
	SDL_GL_MakeCurrent(window_.get(), main_context_);

	glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
	glClearColor(0.5, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window_.get());
}
