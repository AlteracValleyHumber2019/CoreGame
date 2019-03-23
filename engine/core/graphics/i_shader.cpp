#include "pav_pch.h"
#include "i_shader.h"

pav::IShader::IShader(ShaderType shader_type) :
	shader_type_(shader_type)
{
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
	if (index < children_.size())
	{
		return children_.at(index).get();
	}

	return nullptr;
}

pav::ShaderType pav::IShader::GetShaderType() const
{
	return shader_type_;
}
