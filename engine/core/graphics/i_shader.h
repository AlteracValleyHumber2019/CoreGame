#ifndef I_SHADER_H
#define I_SHADER_H

#include "shader_common.h"
#include "../util/wrappers/type_wrappers.h"

namespace pav
{
	class IShaderProgram;

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
		 * \fn	IShader::IShader(ShaderType shader_type);
		 *
		 * \brief	Constructor
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param	shader_type	Type of the shader.
		 */
		IShader(ShaderType shader_type);

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

		/**
		 * \fn	IShader* IShader::GetShaderAt(const size_t index);
		 *
		 * \brief	Gets shader at index
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param	index	Get the child shader at index.
		 *
		 * \returns	Null if it fails, else the shader at.
		 */
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
		virtual void CombineChildShaders() = 0;

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
		 * \fn	virtual void IShader::SetShaderInt(std::string&& name, const int value) = 0;
		 *
		 * \brief	Sets shader int
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param [in]	name 	The name.
		 * \param 	  	value	The value.
		 */
		virtual void SetShaderInt(std::string&& name, const int value) = 0;

		/**
		 * \fn	virtual void IShader::SetShaderFloat(std::string&& name, const float value) = 0;
		 *
		 * \brief	Sets shader float
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param [in]	name 	The name.
		 * \param 	  	value	The value.
		 */
		virtual void SetShaderFloat(std::string&& name, const float value) = 0;

		/**
		 * \fn	virtual void IShader::SetShaderTransform(std::string&& name, const glm::mat4 value) = 0;
		 *
		 * \brief	Sets shader transform
		 *
		 * \author	Jaymie
		 * \date	3/17/2019
		 *
		 * \param [in]	name 	The name.
		 * \param 	  	value	The value.
		 */
		virtual void SetShaderTransform(std::string&& name, const glm::mat4 value) = 0;

	};
}

#endif // I_SHADER_H