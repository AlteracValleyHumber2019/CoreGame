#include "pav_pch.h"
#include "mesh_component.h"
#include "core/graphics/renderable_object_factory.h"
#include "transform_component.h"
#include "../i_game_object.h"
#include "camera_component.h"

pav::MeshComponent::MeshComponent(IGameObjectBase* owner) :
	IComponent<MeshComponent, 3>::IComponent(owner)
{
}

void pav::MeshComponent::Update(const float delta_time)
{
	IGameObjectBase* owner = GetOwner();

	TransformComponent* this_trans = dynamic_cast<TransformComponent*>(owner->GetComponent<TransformComponent>());

	CameraComponent* cam = dynamic_cast<CameraComponent*>(owner->GetManager()->component_manager_->GetComponent<CameraComponent>());

	// Model Matrix
	glm::mat4 model = this_trans->GetPosMatrix() * this_trans->GetRotMatrix() * this_trans->GetScaleMatrix();
	
	// View Matrix
	cam->UpdateCamera();
	TransformComponent* cam_trans = dynamic_cast<TransformComponent*>(cam->GetOwner()->GetComponent<TransformComponent>());
	glm::vec3 cam_pos = glm::vec3((cam_trans->GetPosMatrix() * cam_trans->GetRotMatrix() * cam_trans->GetScaleMatrix()) * glm::vec4(0.f, 0.f, 0.f, 1.f));
	glm::mat4 view =glm::lookAt(cam_pos, cam_pos + cam->GetFront(), cam->GetUp());

	// Projection Matrix
	glm::mat4 projection = glm::perspective(95.0f, 800.f / 600.0f, 0.1f, 1000.f);

	// Set
	renderable_object_->SetModelMatrix(model);
	renderable_object_->SetViewMatrix(view);
	renderable_object_->SetProjectionMatrix(projection);

	renderable_object_->Draw();
}

void pav::MeshComponent::LoadMeshData(ModelResource* model, IShaderResource* shader)
{
	renderable_object_ = RenderableObjectFactory::Make(model, shader);
}
