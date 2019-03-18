#include "pav_pch.h"
#include "opengl_shader.h"

void pav::OpenGLShader::SetShaderCode(std::string&& code)
{
	shader_code_ = code;
}

void pav::OpenGLShader::CompileShaders()
{
	// The source code of each child shader in order
	std::vector<const GLchar*> sources;

	// Shader search DFS lambda
	std::function<void(IShader*)> ss_dfs =
		[&sources, &ss_dfs](IShader* root)->void
	{
		// Add root code
		sources.emplace_back(root->GetShaderCode().c_str());

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
	glShaderSource(shader_, sources.size(), &sources[0], nullptr);

	// Compile
	glCompileShader(shader_);
}

GAPIUInt pav::OpenGLShader::RetrieveShader()
{
	return shader_;
}

void pav::OpenGLShader::DisposeShader()
{
	glDeleteShader(shader_);
}
