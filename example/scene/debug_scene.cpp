#include "pav_pch.h"
#include "debug_scene.h"

#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include "core/resource_system/resource.h"

void DebugScene::BeginScene(WindowType* win)
{
	this->win = win;
}

void DebugScene::EndScene()
{
}

void DebugScene::Update(const float delta_time)
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(win);
	ImGui::NewFrame();

	ImGui::SetNextWindowPos(ImVec2(10, 10));
	ImGui::Begin("Welp Shader Debug Tool");

	ImGui::Text("Not being passive aggressive here");

	ImGui::End();

	ImGui::EndFrame();
}

void DebugScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
}
