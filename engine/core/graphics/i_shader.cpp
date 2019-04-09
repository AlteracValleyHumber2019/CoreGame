#include "pav_pch.h"
#include "i_shader.h"

void pav::IShader::SetShaderType(const ShaderType type)
{
	shader_type_ = type;
}

void pav::IShader::AddChildShader(std::unique_ptr<IShader>&& child)
{
	children_.emplace_back(std::move(child));
}

std::string pav::IShader::GetShaderCode() const
{
	return shader_code_;
}

size_t pav::IShader::GetChildrenSize() const
{
	return children_.size();
}

pav::IShader* pav::IShader::GetShaderAt(const size_t index)
{
	return nullptr;
}

pav::ShaderType pav::IShader::GetShaderType() const
{
	return shader_type_;
}
