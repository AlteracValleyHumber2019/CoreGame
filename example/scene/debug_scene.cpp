#include "pav_pch.h"
#include "debug_scene.h"

#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include "core/resource_system/resource.h"
#include "core/dependent/resource/gl_shader_resource.h"
#include "core/dependent/opengl/gl_renderable_object.h"

void DebugScene::BeginScene(WindowType* win)
{
	this->win = win;

	model_res_ = std::make_unique<pav::ModelResource>();
	pav::ModelLoadInfo info;
	info.ModelFormat = pav::ModelLoadInfo::ModelFormatType::OBJ;

	model_res_->Load("assets/models/fml.obj", std::move(info));

	shader_res_ = std::make_unique<pav::GLShaderResource>();

	shader_res_->Load("assets/shaders/test_shader.json");

	pav::GLRenderableObject object(model_res_.get(), shader_res_.get());
	object.Draw();
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