#ifndef GL_RENDERABLE_OBJECT
#define GL_RENDERABLE_OBJECT

#include "core/graphics/i_renderable_object.h"
#include "core/util/wrappers/type_wrappers.h"
#include "opengl_shader_program.h"

namespace pav
{
	/**
	 * \class	GLRenderableObject
	 *
	 * \brief	A renderable object concrete class inheriting from the interface counterpart. This one is for OpenGL usage.
	 *
	 * \author	Gabriel Kalil
	 * \date	3/17/2019
	 */

	struct GLRenderData
	{
		//Data variables to be used to create the elements used based on the type GLUINT
		GAPIUInt vao;
		GAPIUInt vbo;
		GAPIUInt texture_vbo;
		GAPIUInt instance_vbo = 0;
		GAPIUInt ebo;
		size_t indices_size;

		GAPIUInt texture;
	};

	class GLRenderableObject : public IRenderableObject
	{
		private:
		// The actual model to render
		Model model_mesh_;

		// Shader program
		OpenGLShaderProgram* shader_program_;

		// Render data vao, vbo, ebo
		std::vector<GLRenderData> render_meshes_;

	public:
		GLRenderableObject(ModelResource* model, IShaderResource* shader);

		virtual void Draw() override;

	};
}
#endif // !GL_RENDERABLE_OBJECT

