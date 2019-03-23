#ifndef OPENGL_SHADER_PROGRAM_H
#define OPENGL_SHADER_PROGRAM_H

#include "core/graphics/i_shader_program.h"

namespace pav
{
	class OpenGLShaderProgram : public IShaderProgram
	{
	private:
		GAPIUInt shader_program_id_;

	public:

		virtual void LinkShaders() override;

		virtual void UseShader() override;

		virtual void SetShaderInt(std::string&& name, const int value) override;

		virtual void SetShaderFloat(std::string&& name, const float value) override;

		virtual void SetShaderTransform(std::string&& name, const glm::mat4 value) override;
	};
}

#endif // OPENGL_SHADER_PROGRAM_H