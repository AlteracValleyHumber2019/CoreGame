#ifndef I_SHADER_H
#define I_SHADER_H

#include "shader_common.h"
#include "../util/wrappers/type_wrappers.h"

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
		virtual void AddChildShader(std::unique_ptr<IShader>&& child);

		/**
		 * \fn	std::string IShader::GetShaderCode() const;
		 *
		 * \brief	Gets shader code
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \returns	The shader code.
		 */
		std::string GetShaderCode() const;

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

		/**
		 * \fn	ShaderType IShader::GetShaderType() const;
		 *
		 * \brief	Gets shader type
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \returns	The shader type.
		 */
		ShaderType GetShaderType() const;

		/**
		 * \fn	virtual void IShader::CombineChildShaders() = 0;
		 *
		 * \brief	Combine child shaders
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 */
		virtual void CompileShaders() = 0;

		/**
		 * \fn	virtual GAPIUInt IShader::RetriveShader() = 0;
		 *
		 * \brief	Retrieve shader
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \returns	A GAPIUInt.
		 */
		virtual GAPIUInt RetrieveShader() = 0;

		/**
		 * \fn	virtual void IShader::DisposeShader() = 0;
		 *
		 * \brief	Dispose shader
		 *
		 * \author	Jaymie
		 * \date	4/7/2019
		 */
		virtual void DisposeShader() = 0;

	public:
		IShader(ShaderType shader_type);
	};
}

#endif // I_SHADER_H