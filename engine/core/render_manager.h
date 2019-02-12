#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include "i_manager.h"
#include "i_renderer.h"

namespace pav
{
	/**
	 * \class	RenderManager
	 *
	 * \brief	Manager for renders.
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class RenderManager : public IManager
	{
	public:
		virtual IRenderer* CreateRenderer() = 0;
	};
}

#endif // RENDER_MANAGER_H
