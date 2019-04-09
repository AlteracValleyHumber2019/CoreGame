#ifndef GL_SHADER_RESOURCE
#define GL_SHADER_RESOURCE

#include "core/resource_system/resource.h"
#include "../opengl/opengl_shader.h"

namespace pav
{
	class GLShaderResource : public Resource<GLShaderResource, OpenGLShader*, std::string>
	{
	private:
		OpenGLShader* resource;

	public:
		virtual OpenGLShader* GetData() override;

		virtual OpenGLShader* GetData() const override;

		virtual bool Load(std::string&& args) override;

	};
}

#endif // !GL_SHADER_RESOURCE
