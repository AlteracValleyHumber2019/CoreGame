#include "pav_pch.h"
#include "mvp_scene.h"
#include "core/dependent/resource/gl_shader_resource.h"

void MVPScene::BeginScene(WindowType* window)
{
	// Resource loading
	go_plane_model_ = std::make_unique<pav::ModelResource>();

	// Generic shader
	generic_shader_ = std::make_unique<pav::GLShaderResource>();
	generic_shader_->Load("assets/shaders/test_shader.json");

	// Debug camera
	go_d_cam_ = dynamic_cast<pav::GameObject*>(GetSECManager()->AddGameObject<pav::GameObject>("go_camera"));
	// Debug camera components
	go_d_cam_transform_ = dynamic_cast<pav::TransformComponent*>(GetSECManager()->AddComponent<pav::TransformComponent>(go_d_cam_));
	go_d_cam_transform_->SetPosition(glm::vec3(0.f, 0.f, 0.f));
	go_d_cam_transform_->SetScale(glm::vec3(1.f, 1.f, 1.f));
	// Camera comp
	go_d_cam_comp_ = dynamic_cast<pav::CameraComponent*>(GetSECManager()->AddComponent<pav::CameraComponent>(go_d_cam_));

	// Plane
	pav::ModelLoadInfo info_plane;
	info_plane.ModelFormat = pav::ModelLoadInfo::ModelFormatType::OBJ;
	go_plane_model_->Load("assets/models/Terrain.obj", std::move(info_plane));

	// Plane
	go_plane_ = dynamic_cast<pav::GameObject*>(GetSECManager()->AddGameObject<pav::GameObject>("go_plane"));
	// Plane Components
	go_plane_transform_ = dynamic_cast<pav::TransformComponent*>(GetSECManager()->AddComponent<pav::TransformComponent>(go_plane_));
	go_plane_transform_->SetPosition(glm::vec3(0.f, 0.f, 0.f));
	go_plane_transform_->SetScale(glm::vec3(10.f, 10.f, 10.f));
	// Plane Mesh
	go_plane_mesh_ = dynamic_cast<pav::MeshComponent*>(GetSECManager()->AddComponent<pav::MeshComponent>(go_plane_));
	// Mesh data
	
}

void MVPScene::SetupEngineEvents(pav::EventAttorney* event_attorney)
{
}

void MVPScene::Update(const float delta_time)
{
	go_plane_mesh_->Update(delta_time);
}
