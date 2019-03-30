#ifndef GL_RENDERABLE_OBJECT
#define GL_RENDERABLE_OBJECT

#include "core/graphics/i_renderable_object.h"
#include "core/util/wrappers/type_wrappers.h"

namespace pav {
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
		GAPIUInt texture_vbo;
		GAPIUInt instance_vbo = 0;
		GAPIUInt ebo;
		size_t indices_size;

		GAPIUInt texture;
	};

	class GLRenderableObject : public IRenderableObject
	{
	protected:
		GLRenderData gl_renderable_data_;

		//TODO : Finish implementation of the class with all the other components like shader, material, texture, etc.
	};
}
#endif // !GL_RENDERABLE_OBJECT

