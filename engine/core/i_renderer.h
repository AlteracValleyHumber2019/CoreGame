#ifndef I_RENDERER_H
#define I_RENDERER_H
#include "graphics/i_renderable_object.h"

namespace pav
{
	/**
	 * \class	IRenderer
	 *
	 * \brief	A renderer interface used to render any IRenderableObject objects
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class IRenderer
	{
	public:
		virtual void Render(IRenderableObject* object) = 0;
	};
}

#endif // I_RENDERER_H
