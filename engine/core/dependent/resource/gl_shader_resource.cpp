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
			result.append("\n");
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
	return resource.get();
}

bool pav::GLShaderResource::Load(std::string&& args)
{
	resource = std::make_unique<OpenGLShaderProgram>();

	// Read shader info file
	std::string shader_info_file = ReadShaderCodeFromFile(std::move(args));
	nlohmann::json shader_json = nlohmann::json::parse(shader_info_file);

	// Iterate through shaders
	for (auto shaders : shader_json["shaders"]["shader"])
	{
		std::string shader_path = shaders["path"];
		std::string shader_type = shaders["type"];

		// Read GLSL shader code
		std::string shader_code = ReadShaderCodeFromFile(std::move(shader_path));

		// Insert GLSL shader code
		std::unique_ptr<OpenGLShader> shader = std::make_unique<OpenGLShader>();
		shader->SetShaderCode(std::move(shader_code));

		// Set shader type
		if (shader_type == "VERTEX_SHADER")
		{
			shader->SetShaderType(ShaderType::VERTEX_SHADER);
		}
		else if (shader_type == "GEOMETRY_SHADER")
		{
			shader->SetShaderType(ShaderType::GEOMETRY_SHADER);
		}
		else if (shader_type == "TESSELLATION_SHADER")
		{
			shader->SetShaderType(ShaderType::TESSELLATION_SHADER);
		}
		else if (shader_type == "FRAGMENT_SHADER")
		{
			shader->SetShaderType(ShaderType::FRAGMENT_SHADER);
		}

		resource->AddShader(std::move(shader));
	}

	// Linking
	resource->LinkShaders();

	return true;
}

pav::IShaderProgram* pav::GLShaderResource::GetData() const
{
	return resource.get();
}
