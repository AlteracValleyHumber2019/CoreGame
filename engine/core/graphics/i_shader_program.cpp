#include "pav_pch.h"
#include "i_shader_program.h"
#include "i_shader.h"

void pav::IShaderProgram::AddShader(std::unique_ptr<IShader>&& shader)
{
	member_shaders_[(size_t)shader->GetShaderType()] = std::move(shader);
}
