#include "pav_pch.h"
#include "opengl_shader.h"

void pav::OpenGLShader::SetShaderCode(std::string&& code)
{
	shader_code_ = code;
}

void pav::OpenGLShader::CompileShaders()
{
	// The source code of each child shader in order
	std::vector<std::string> sources;

	// Shader search DFS lambda
	std::function<void(IShader*)> ss_dfs =
		[&sources, &ss_dfs](IShader* root)->void
	{
		// Add root code
		sources.emplace_back(root->GetShaderCode());

		// For each root's child
		for (size_t i = 0; i < root->GetChildrenSize(); i++)
		{
			// Recursion into i-th shader
			ss_dfs(root->GetShaderAt(i));
		}
	};

	// Begin search
	ss_dfs(this);

	// Set shader type
	GLenum opengl_shader_type;

	// Translate engine shader type to OpenGL shader type
	switch (shader_type_)
	{
	case pav::ShaderType::VERTEX_SHADER:
		opengl_shader_type = GL_VERTEX_SHADER;
		break;
	case pav::ShaderType::TESSELLATION_SHADER:
		// Tessellation shaders are made from tessellation shader units
		// Implement later as needed.
		break;
	case pav::ShaderType::GEOMETRY_SHADER:
		opengl_shader_type = GL_GEOMETRY_SHADER;
		break;
	case pav::ShaderType::FRAGMENT_SHADER:
		opengl_shader_type = GL_FRAGMENT_SHADER;
		break;
	}

	// Create shader
	shader_ = glCreateShader(opengl_shader_type);

	// Attach all shader code
	std::vector<const GLchar*> cstr_sources;
	for (size_t i = 0; i < sources.size(); i++)
	{
		cstr_sources.emplace_back(sources[i].c_str());
	}
	glShaderSource(shader_, cstr_sources.size(), &cstr_sources[0], nullptr);

	// Compile
	glCompileShader(shader_);

	// Assert
#ifdef _DEBUG
	int success;
	char info_log[512];
	glGetShaderiv(shader_, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		std::string shader_type_str_;
		switch (shader_type_)
		{
		case pav::ShaderType::VERTEX_SHADER:
			shader_type_str_ = "VERTEX_SHADER";
			break;
		case pav::ShaderType::TESSELLATION_SHADER:
			shader_type_str_ = "TESSELLATION_SHADER";
			break;
		case pav::ShaderType::GEOMETRY_SHADER:
			shader_type_str_ = "GEOMETRY_SHADER";
			break;
		case pav::ShaderType::FRAGMENT_SHADER:
			shader_type_str_ = "FRAGMENT_SHADER";
			break;
		}

		glGetShaderInfoLog(shader_, 512, nullptr, info_log);
		PAV_ASSERT(false, info_log)
	}
#endif
}

GAPIUInt pav::OpenGLShader::RetrieveShader()
{
	// Assert
	PAV_ASSERT(shader_ != NULL, INVALID_SHADER)

	return shader_;
}

void pav::OpenGLShader::DisposeShader()
{
	glDeleteShader(shader_);
	shader_ = NULL;
}
