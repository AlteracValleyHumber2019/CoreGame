#include "pav_pch.h"
#include "i_shader_program.h"
#include "i_shader.h"

void pav::IShaderProgram::AddShader(std::unique_ptr<IShader>&& shader)
{
	size_t shader_index = (size_t)shader->GetShaderType();

	if (member_shaders_.at(shader_index) == nullptr)
	{
		member_shaders_.at(shader_index) = std::move(shader);
	}
}
