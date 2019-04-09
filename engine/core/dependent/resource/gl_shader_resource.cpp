#include "pav_pch.h"
#include "gl_shader_resource.h"

#include <nlohmann/json.hpp>
#include<iostream>
#include<fstream>

std::string pav::GLShaderResource::ReadShaderCodeFromFile(std::string&& path)
{

}

pav::OpenGLShaderProgram* pav::GLShaderResource::GetData()
{
	return resource;
}

bool pav::GLShaderResource::Load(std::string&& args)
{
	nlohmann::json shader_json = nlohmann::json::parse(std::move(args));

	// Vertex shader
	std::string vertex_shader_path = shader_json["vertex_shader_path"];

	// Fragment shader
	std::string fragment_shader_path = shader_json["fragment_shader_path"];

	return true;
}

pav::OpenGLShaderProgram* pav::GLShaderResource::GetData() const
{
	return resource;
}
