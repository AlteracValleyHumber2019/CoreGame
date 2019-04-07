#include "pav_pch.h"
#include "i_shader.h"

size_t pav::IShader::GetChildrenSize() const
{
	return children_.size();
}

pav::IShader* pav::IShader::GetShaderAt(const size_t index)
{
	return nullptr;
}
