#ifndef I_SHADER_H
#define I_SHADER_H

#include "shader_common.h"

namespace pav
{
	/**
	 * \class	IShader
	 *
	 * \brief	A shader.
	 *
	 * \author	Jaymie
	 * \date	3/17/2019
	 */
	class IShader
	{
	protected:
		/** \brief	Type of the shader */
		ShaderType shader_type_;

		/** \brief	The shader code */
		std::string shader_code_;

		/** \brief	The children shaders */
		std::vector <std::unique_ptr<IShader>> children_;

	public:

		/**
		 * \fn	virtual void IShader::SetShaderCode(std::string&& code) = 0;
		 *
		 * \brief	Sets shader code
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param [in]	code	The code.
		 */
		virtual void SetShaderCode(std::string&& code) = 0;

		/**
		 * \fn	virtual void IShader::AddChildShader(std::unique_ptr<IShader>&& child) = 0;
		 *
		 * \brief	Adds a child shader
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param [in]	child	The child.
		 */
		virtual void AddChildShader(std::unique_ptr<IShader>&& child) = 0;

		/**
		 * \fn	size_t IShader::GetChildrenSize() const;
		 *
		 * \brief	Gets children size
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \returns	The children size.
		 */
		size_t GetChildrenSize() const;

		IShader* GetShaderAt(const size_t index);

	};
}

#endif // I_SHADER_H