#include "pav_pch.h"
#include "gl_shader_resource.h"
#include "../opengl/opengl_shader.h"

#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

std::string pav::GLShaderResource::ReadShaderCodeFromFile(std::string&& path)
{
	// The final result
	std::string result = "";

	// Construct path
	std::string file_path = path + ".json";

	// File load info
	std::string line;
	std::ifstream shader_info_file(file_path);

	// Able to open file
	if (shader_info_file.is_open())
	{
		// Read each line
		while (getline(shader_info_file, line))
		{
			result += line;
		}

		// Close file
		shader_info_file.close();
	}
	else
	{
		// Error
		PAV_ASSERT(false, "Cannot open shader info file");
	}

	return result;
}

pav::OpenGLShaderProgram* pav::GLShaderResource::GetData()
{
	return resource;
}

bool pav::GLShaderResource::Load(std::string&& args)
{
	// Read shader info file
	std::string shader_info_file = ReadShaderCodeFromFile(std::move(args));
	nlohmann::json shader_json = nlohmann::json::parse(shader_info_file);

	// Iterate through shaders
	for (auto it = shader_json["shaders"].begin(); it != shader_json["shaders"].end(); ++it)
	{
		// Read GLSL shader code
		std::string shader_code = ReadShaderCodeFromFile(it.value());

		// Insert GLSL shader code
		std::unique_ptr<OpenGLShader> shader = std::make_unique<OpenGLShader>();
		shader->SetShaderCode(std::move(shader_code));

		resource->AddShader(std::move(shader));
	}

	// Linking
	resource->LinkShaders();

	return true;
}

pav::OpenGLShaderProgram* pav::GLShaderResource::GetData() const
{
	return resource;
}
