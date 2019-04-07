#ifndef I_SHADER_PROGRAM_H
#define I_SHADER_PROGRAM_H

#include "shader_common.h"
#include "i_shader.h"

namespace pav
{
	/**
	 * \file	shader_program.h.
	 *
	 * \brief	Declares the shader program class
	 */
	class IShaderProgram
	{
	private:
		std::array<std::unique_ptr<IShader>, SHADER_TYPE_COUNT> member_shaders_;

	public:
		IShaderProgram() = default;
		virtual ~IShaderProgram() = default;

		/**
		 * \fn	void ShaderProgram::AddShader(std::unique_ptr<IShader>&& shader);
		 *
		 * \brief	Adds a shader
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param [in]	shader	The shader.
		 */
		void AddShader(std::unique_ptr<IShader>&& shader);

		/**
		 * \fn	virtual void IShaderProgram::CompileShader() = 0;
		 *
		 * \brief	Compile shader
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 */
		virtual void CompileShader() = 0;

		/**
		 * \fn	virtual void IShaderProgram::UseShader() = 0;
		 *
		 * \brief	Use shader
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 */
		virtual void UseShader() = 0;

	};

}

#endif // I_SHADER_PROGRAM_H
