#ifndef MVP_SCENE_H
#define MVP_SCENE_H

#include "core/i_scene.h"
#include "core/event_attorney.h"
#include "core/entity_component/i_game_object.h"
#include "core/entity_component/component/transform_component.h"
#include "core/entity_component/component/mesh_component.h"
#include "core/dependent/resource/model_resource.h"
#include "core/entity_component/component/camera_component.h"

class MVPScene : public pav::IScene
{
private:
	std::unique_ptr<pav::IShaderResource> generic_shader_;

	// Debug camera
	pav::GameObject* go_d_cam_;
	pav::TransformComponent* go_d_cam_transform_;
	pav::CameraComponent* go_d_cam_comp_;

	// Plane
	pav::GameObject* go_plane_;
	pav::TransformComponent* go_plane_transform_;
	pav::MeshComponent* go_plane_mesh_;
	std::unique_ptr<pav::ModelResource> go_plane_model_;

	// Player client
	pav::GameObject* go_player_client_;
	pav::TransformComponent* go_player_client_transform_;
	pav::MeshComponent* go_player_client_mesh_;
	std::unique_ptr<pav::ModelResource> go_player_client_model_;

	//Second Player Client
	pav::GameObject* go_player_client_2;
	pav::TransformComponent* go_player_client_transform_2;
	pav::MeshComponent* go_player_client_mesh_2;
	std::unique_ptr<pav::ModelResource> go_player_client_model_2;

	bool isP1Tagged;
	bool isP2Tagged;

	void OnKeyHold(pav::KeyCode keycode);
public:

	virtual void BeginScene(WindowType* window) override;


	virtual void SetupEngineEvents(pav::EventAttorney* event_attorney) override;


	virtual void Update(const float delta_time) override;

};

#endif // MVP_SCENE_H
