#include "pav_pch.h"
#include "gl_shader_resource.h"

pav::OpenGLShader* pav::GLShaderResource::GetData()
{
	return resource;
}

bool pav::GLShaderResource::Load(std::string&& args)
{
	resource->SetShaderCode(std::move(args));
	return true;
}

pav::OpenGLShader* pav::GLShaderResource::GetData() const
{
	return resource;
}
