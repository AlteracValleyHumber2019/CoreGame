#include "pav_pch.h"
#include "mvp_scene.h"
#include "core/dependent/resource/gl_shader_resource.h"

void MVPScene::BeginScene(WindowType* window)
{
	// Resource loading
	go_plane_model_ = std::make_unique<pav::ModelResource>();
	go_player_client_model_ = std::make_unique<pav::ModelResource>();

	// Generic shader
	generic_shader_ = std::make_unique<pav::GLShaderResource>();
	generic_shader_->Load("assets/shaders/test_shader.json");

	// Debug camera
	go_d_cam_ = dynamic_cast<pav::GameObject*>(GetSECManager()->AddGameObject<pav::GameObject>("go_camera"));
	// Debug camera components
	go_d_cam_transform_ = dynamic_cast<pav::TransformComponent*>(GetSECManager()->AddComponent<pav::TransformComponent>(go_d_cam_));
	go_d_cam_transform_->SetPosition(glm::vec3(0.f, 20.f, 0.f));
	go_d_cam_transform_->SetScale(glm::vec3(1.f, 1.f, 1.f));
	// Camera comp
	go_d_cam_comp_ = dynamic_cast<pav::CameraComponent*>(GetSECManager()->AddComponent<pav::CameraComponent>(go_d_cam_));
	go_d_cam_comp_->SetOffset(glm::vec3(0.f, 105.f, 155.f));

	// Plane
	pav::ModelLoadInfo info_plane;
	info_plane.ModelFormat = pav::ModelLoadInfo::ModelFormatType::OBJ;
	go_plane_model_->Load("assets/models/Terrain.obj", std::move(info_plane));

	// Player
	pav::ModelLoadInfo info_player;
	info_player.ModelFormat = pav::ModelLoadInfo::ModelFormatType::OBJ;
	go_player_client_model_->Load("assets/models/Player.obj", std::move(info_player));

	// Plane
	go_plane_ = dynamic_cast<pav::GameObject*>(GetSECManager()->AddGameObject<pav::GameObject>("go_plane"));
	// Plane Components
	go_plane_transform_ = dynamic_cast<pav::TransformComponent*>(GetSECManager()->AddComponent<pav::TransformComponent>(go_plane_));
	go_plane_transform_->SetPosition(glm::vec3(0.f, 0.f, 0.f));
	go_plane_transform_->SetScale(glm::vec3(10.f, 10.f, 10.f));
	// Plane Mesh
	go_plane_mesh_ = dynamic_cast<pav::MeshComponent*>(GetSECManager()->AddComponent<pav::MeshComponent>(go_plane_));
	go_plane_mesh_->LoadMeshData(go_plane_model_.get(), generic_shader_.get());
	// Mesh data
	
	// Player client
	go_player_client_ = dynamic_cast<pav::GameObject*>(GetSECManager()->AddGameObject<pav::GameObject>("go_player_client"));
	// Player client components
	go_player_client_transform_ = dynamic_cast<pav::TransformComponent*>(GetSECManager()->AddComponent<pav::TransformComponent>(go_player_client_));
	go_player_client_transform_->SetPosition(glm::vec3(0.f, 50.f, 0.f));
	go_player_client_transform_->SetScale(glm::vec3(.1f, .1f, .1f));
	// Player mesh
	go_player_client_mesh_ = dynamic_cast<pav::MeshComponent*>(GetSECManager()->AddComponent<pav::MeshComponent>(go_player_client_));
	go_player_client_mesh_->LoadMeshData(go_player_client_model_.get(), generic_shader_.get());
	
}

void MVPScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
	event_attorney->on_key_hold->Connect(this, &MVPScene::OnKeyHold);
}

void MVPScene::Update(const float delta_time)
{
	go_d_cam_transform_->SetPosition(go_player_client_transform_->GetPosition());

	go_plane_mesh_->Update(delta_time);
	go_player_client_mesh_->Update(delta_time);
}

void MVPScene::OnKeyHold(pav::KeyCode keycode)
{
	switch (keycode)
	{
	case pav::KEY_A:
		go_player_client_transform_->SetPosition(go_player_client_transform_->GetPosition() + glm::vec3(1, 0, 0) * 5.f);
		break;
	case pav::KEY_D:
		go_player_client_transform_->SetPosition(go_player_client_transform_->GetPosition() + glm::vec3(-1, 0, 0) * 5.f);
		break;
	case pav::KEY_W:
		go_player_client_transform_->SetPosition(go_player_client_transform_->GetPosition() + glm::vec3(0, 0, 1) * 5.f);
		break;
	case pav::KEY_S:
		go_player_client_transform_->SetPosition(go_player_client_transform_->GetPosition() + glm::vec3(0, 0, -1) *5.f);
		break;
	case pav::KEY_E:
		go_d_cam_comp_->SetYaw(go_d_cam_comp_->GetYaw() - 1);
		break;
	case pav::KEY_Q:
		go_d_cam_comp_->SetYaw(go_d_cam_comp_->GetYaw() + 1);
		break;
	case pav::KEY_Z:
	{
		float new_val = go_d_cam_comp_->GetPitch() + 1;
		if (new_val > 90) new_val = 90;

		go_d_cam_comp_->SetPitch(new_val);
	}
	break;
	case pav::KEY_X:
	{
		float new_val = go_d_cam_comp_->GetPitch() - 1;
		if (new_val < -90) new_val = -90;

		go_d_cam_comp_->SetPitch(new_val);
	}
	break;
	}
}