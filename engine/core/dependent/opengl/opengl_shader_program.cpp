#include "pav_pch.h"
#include "opengl_shader_program.h"

void pav::OpenGLShaderProgram::LinkShaders()
{
	for (auto& shader : member_shaders_)
	{
		if (shader != nullptr)
		{
			// Attach and compile all of this shader
			shader->CompileShaders();

			// Attach to this program
			glAttachShader(shader_program_id_, shader->RetrieveShader());
		}
	}

	// Linking
	glLinkProgram(shader_program_id_);

	// Garbage collection
	for (auto& shader : member_shaders_)
	{
		if (shader != nullptr)
		{
			shader->DisposeShader();
		}
	}

	// Assert
#ifdef _DEBUG
	int success;
	char info_log[512];
	glGetProgramiv(shader_program_id_, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader_program_id_, 512, nullptr, info_log);
		PAV_ASSERT(false, SHADER_LINKING_FAILED(info_log))
	}
#endif
}

void pav::OpenGLShaderProgram::UseShader()
{
	PAV_ASSERT(shader_program_id_ == NULL, INVALID_SHADER_PROGRAM)

	glUseProgram(shader_program_id_);
}

void pav::OpenGLShaderProgram::SetShaderInt(std::string&& name, const int value)
{
	const auto location = glGetUniformLocation(shader_program_id_, (GLchar*)name.c_str());
	glUniform1i(location, value);

	// Assert check
	PAV_ASSERT(!(location == -1) , SHADER_UNIFORM_LOCATION_UNDEFINED(name.c_str()));
}

void pav::OpenGLShaderProgram::SetShaderFloat(std::string&& name, const float value)
{
	const auto location = glGetUniformLocation(shader_program_id_, (GLchar*)name.c_str());
	glUniform1f(location, value);

	// Assert check
	PAV_ASSERT(!(location == -1), SHADER_UNIFORM_LOCATION_UNDEFINED(name.c_str()));
}

void pav::OpenGLShaderProgram::SetShaderTransform(std::string&& name, const glm::mat4 value)
{
	auto location = glGetUniformLocation(shader_program_id_, (GLchar*)name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));

	// Assert check
	PAV_ASSERT(!(location == -1), SHADER_UNIFORM_LOCATION_UNDEFINED(name.c_str()));
}
