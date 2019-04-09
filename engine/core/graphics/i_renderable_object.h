#ifndef I_RENDERABLE_OBJECT
#define I_RENDERABLE_OBJECT
#include "i_shader_program.h"
#include "material.h"
#include "mesh.h"

namespace pav
{
	/**
	 * \class	IRenderableObject
	 *
	 * \brief	A renderable object interface class that contains the important members of an object.
	 *
	 * \author	Gabriel Kalil
	 * \date	3/17/2019
	 */

	class IRenderableObject {
	protected:
		glm::mat4 model_;
		glm::mat4 view_;
		glm::mat4 projection_;
		glm::mat4 transform_;

		//Insert Shader and Material here
		std::unique_ptr<IShaderProgram> shader_;
		Material mat_;
		Mesh mesh_;

	public:

		IRenderableObject(const Material& mat, const Mesh& mesh) {
			model_ = glm::mat4(1.0f);
			view_ = glm::mat4(1.0f);
			projection_ = glm::mat4(1.0f);
			transform_ = glm::mat4(1.0f);
			mat_ = mat;
			mesh_ = mesh;
		}

		virtual ~IRenderableObject() = default;

		virtual void Draw() = 0;

		inline void SetModelMatrix(const glm::mat4& matrix)
		{
			model_ = matrix;
		}

		inline void SetViewMatrix(const glm::mat4& matrix)
		{
			view_ = matrix;
		}

		inline void SetProjectionMatrix(const glm::mat4& matrix)
		{
			projection_ = matrix;
		}

		inline void SetTransform(const glm::mat4& matrix)
		{
			transform_ = matrix;
		}

	};

}

#endif // !I_RENDERABLE_OBJECT

