#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "../i_component.h"
#include "core/dependent/resource/i_shader_resource.h"
#include "core/dependent/resource/model_resource.h"
#include "core/graphics/i_renderable_object.h"

namespace pav
{
	class MeshComponent : IComponent<MeshComponent, 3>
	{
	private:
		std::unique_ptr<IRenderableObject> renderable_object_;

	public:

		virtual void Update(const float delta_time) override;

		void LoadMeshData(ModelResource* model, IShaderResource* shader);
	};
}

#endif // MESH_COMPONENT_H