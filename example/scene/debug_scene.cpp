#include "pav_pch.h"
#include "debug_scene.h"

#include "core/resource_system/resource.h"
#include "core/dependent/resource/gl_shader_resource.h"
#include "core/entity_component/component/transform_component.h"
#include "core/entity_component/component/camera_component.h"

pav::TransformComponent* trans_comp;
pav::CameraComponent* cam_comp;
pav::GameObject* go;

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

	go = dynamic_cast<pav::GameObject*>(GetSECManager()->AddGameObject<pav::GameObject>("go"));

	trans_comp = dynamic_cast<pav::TransformComponent*>(GetSECManager()->AddComponent<pav::TransformComponent>(go));
	trans_comp->SetPosition(glm::vec3(0, 0, 0));
	trans_comp->SetScale(glm::vec3(1, 1, 1));

	cam_comp = dynamic_cast<pav::CameraComponent*>(GetSECManager()->AddComponent<pav::CameraComponent>(go));
}

void DebugScene::EndScene()
{
}

void DebugScene::Update(const float delta_time)
{
	glm::mat4 model(1.f);
	model = glm::translate(model, glm::vec3(1, 1, 1));
	model = glm::scale(model, glm::vec3(2, 2, 2));

	object_->SetModelMatrix(model);

	cam_comp->UpdateCamera();
	glm::vec3 cam_pos = glm::vec3((trans_comp->GetPosMatrix() * trans_comp->GetScaleMatrix()) * glm::vec4(0.f, 0.f, 0.f, 1.f));
	object_->SetViewMatrix(glm::lookAt(cam_pos, cam_pos + cam_comp->GetFront(), cam_comp->GetUp()));

	object_->SetProjectionMatrix(glm::perspective(90.0f, 4.0f / 3.0f, 0.1f, 1000.f));
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
		trans_comp->SetPosition(trans_comp->GetPosition() + glm::vec3(-1, 0, 0));
		break;
	case pav::KEY_D:
		trans_comp->SetPosition(trans_comp->GetPosition() + glm::vec3(1, 0, 0));
		break;
	case pav::KEY_W:
		trans_comp->SetPosition(trans_comp->GetPosition() + glm::vec3(0, 0, -1));
		break;
	case pav::KEY_S:
		trans_comp->SetPosition(trans_comp->GetPosition() + glm::vec3(0, 0, 1));
		break;
	}
}
