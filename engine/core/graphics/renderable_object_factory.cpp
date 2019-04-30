#include "pav_pch.h"
#include "renderable_object_factory.h"
#include "../dependent/opengl/gl_renderable_object.h"

std::unique_ptr<pav::IRenderableObject> pav::RenderableObjectFactory::Make(ModelResource* model, IShaderResource* shader)
{
#ifdef ENGINE_TYPE_GL_SDL
	return std::make_unique<GLRenderableObject>(model, shader);
#endif
}
