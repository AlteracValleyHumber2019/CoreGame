#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include "core/graphics/i_shader.h"

namespace pav
{
	/**
	 * \class	OpenGLShader
	 *
	 * \brief	An OpenGL shader.
	 *
	 * \author	Jaymie
	 * \date	3/17/2019
	 */
	class OpenGLShader : public IShader
	{
	private:
		GAPIUInt shader_;

	public:
		virtual void SetShaderCode(std::string&& code) override;

		virtual void CompileShaders() override;

		virtual GAPIUInt RetrieveShader() override;

		virtual void DisposeShader() override;

	};
}

#endif // OPENGL_SHADER_H