#include "pav_pch.h"
#include "debug_scene.h"

#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

void DebugScene::BeginScene(WindowType* win)
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(win);
	ImGui::NewFrame();

	ImGui::ShowDemoWindow();
}

void DebugScene::EndScene()
{
}

void DebugScene::Update(const float delta_time)
{
}

void DebugScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
}
