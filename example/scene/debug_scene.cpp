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
	glm::mat4 model(1.f);
	model = glm::translate(model, pos);

	object_->SetModelMatrix(model);
	object_->SetProjectionMatrix(glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.f));
	object_->Draw();
}

void DebugScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
	event_attorney->on_key_hold->Connect(this, &DebugScene::OnKeyHold);
}

void DebugScene::OnKeyHold(pav::KeyCode keycode)
{
	switch (keycode)
	{
	case pav::KEY_A:
		pos += glm::vec3(-1, 0, 0);
		break;
	case pav::KEY_D:
		pos += glm::vec3(1, 0, 0);
		break;
	case pav::KEY_W:
		pos += glm::vec3(0, 0, 1);
		break;
	case pav::KEY_S:
		pos += glm::vec3(0, 0, -1);
		break;
	}
}
