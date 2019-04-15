#include "pav_pch.h"
#include "debug_scene.h"

#include "core/resource_system/resource.h"
#include "core/dependent/resource/gl_shader_resource.h"


void DebugScene::BeginScene(WindowType* win)
{
	this->win = win;

	model_res_ = std::make_unique<pav::ModelResource>();
	pav::ModelLoadInfo info;
	info.ModelFormat = pav::ModelLoadInfo::ModelFormatType::OBJ;

	model_res_->Load("assets/models/fml.obj", std::move(info));

	shader_res_ = std::make_unique<pav::GLShaderResource>();

	shader_res_->Load("assets/shaders/test_shader.json");

	object_ = std::make_unique<pav::GLRenderableObject>(model_res_.get(), shader_res_.get());
}

void DebugScene::EndScene()
{
}

void DebugScene::Update(const float delta_time)
{
	object_->Draw();
}

void DebugScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
}
