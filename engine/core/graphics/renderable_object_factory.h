#ifndef RENDERABLE_OBJECT_FACTORY_H
#define RENDERABLE_OBJECT_FACTORY_H

#include "i_renderable_object.h"
#include "../dependent/resource/model_resource.h"
#include "../dependent/resource/i_shader_resource.h"

namespace pav
{
	class RenderableObjectFactory
	{
	public:
		static std::unique_ptr<IRenderableObject> Make(ModelResource* model, IShaderResource* shader);
	};
}

#endif // RENDERABLE_OBJECT_FACTORY_H
