#ifndef GL_SHADER_RESOURCE
#define GL_SHADER_RESOURCE

#include "core/resource_system/resource.h"
#include "../opengl/opengl_shader_program.h"
#include "i_shader_resource.h"

namespace pav
{
	class GLShaderResource : public IShaderResource
	{
	private:
		std::unique_ptr<OpenGLShaderProgram> resource;

		std::string ReadShaderCodeFromFile(std::string&& path);

	public:
		virtual IShaderProgram* GetData() override;

		virtual IShaderProgram* GetData() const override;

		virtual bool Load(std::string&& args) override;

	};
}

#endif // !GL_SHADER_RESOURCE
