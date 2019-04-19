#include "pav_pch.h"
#include "mesh_component.h"
#include "core/graphics/renderable_object_factory.h"

void pav::MeshComponent::Update(const float delta_time)
{
}

void pav::MeshComponent::LoadMeshData(ModelResource* model, IShaderResource* shader)
{
	renderable_object_ = RenderableObjectFactory::Make(model, shader);
}
