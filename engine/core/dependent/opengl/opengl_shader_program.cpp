#include "pav_pch.h"
#include "opengl_shader_program.h"

void pav::OpenGLShaderProgram::LinkShaders()
{
	for (auto& shader : member_shaders_)
	{
		// Attach and compile all of this shader
		shader->CompileShaders();

		// Attach to this program
		glAttachShader(shader_program_id_, shader->RetrieveShader());
	}

	// Linking
	glLinkProgram(shader_program_id_);

	// Garbage collection
	for (auto& shader : member_shaders_)
	{
		shader->DisposeShader();
	}
}

void pav::OpenGLShaderProgram::UseShader()
{
	glUseProgram(shader_program_id_);
}

void pav::OpenGLShaderProgram::SetShaderInt(std::string&& name, const int value)
{
	const auto location = glGetUniformLocation(shader_program_id_, (GLchar*)name.c_str());
	glUniform1i(location, value);
}

void pav::OpenGLShaderProgram::SetShaderFloat(std::string&& name, const float value)
{
	const auto location = glGetUniformLocation(shader_program_id_, (GLchar*)name.c_str());
	glUniform1f(location, value);
}

void pav::OpenGLShaderProgram::SetShaderTransform(std::string&& name, const glm::mat4 value)
{
	auto location = glGetUniformLocation(shader_program_id_, (GLchar*)name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}
