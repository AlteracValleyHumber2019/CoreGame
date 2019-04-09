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

	// File load info
	std::string line;
	std::ifstream shader_info_file(path);

	// Able to open file
	if (shader_info_file.is_open())
	{
		// Read each line
		while (getline(shader_info_file, line))
		{
			result.append(line);
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

pav::IShaderProgram* pav::GLShaderResource::GetData()
{
	return resource;
}

bool pav::GLShaderResource::Load(std::string&& args)
{
	// Read shader info file
	std::string shader_info_file = ReadShaderCodeFromFile(std::move(args));
	nlohmann::json shader_json = nlohmann::json::parse(shader_info_file);

	// Iterate through shaders
	for (auto shaders : shader_json["shaders"])
	{
		for (auto path : shaders)
		{
			std::string shader_path = path.get<std::string>();

			// Read GLSL shader code
			std::string shader_code = ReadShaderCodeFromFile(std::move(shader_path));

			// Insert GLSL shader code
			std::unique_ptr<OpenGLShader> shader = std::make_unique<OpenGLShader>();
			shader->SetShaderCode(std::move(shader_code));

			resource->AddShader(std::move(shader));
		}
	}

	// Linking
	resource->LinkShaders();

	return true;
}

pav::IShaderProgram* pav::GLShaderResource::GetData() const
{
	return resource;
}
