#ifndef GL_SHADER_RESOURCE
#define GL_SHADER_RESOURCE

#include "core/resource_system/resource.h"
#include "../opengl/opengl_shader_program.h"

namespace pav
{
	class GLShaderResource : public Resource<GLShaderResource, OpenGLShaderProgram*, std::string>
	{
	private:
		OpenGLShaderProgram* resource;

		std::string ReadShaderCodeFromFile(std::string&& path);

	public:
		virtual OpenGLShaderProgram* GetData() override;

		virtual OpenGLShaderProgram* GetData() const override;

		virtual bool Load(std::string&& args) override;

	};
}

#endif // !GL_SHADER_RESOURCE
