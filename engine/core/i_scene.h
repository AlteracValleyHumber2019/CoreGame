#ifndef SCENE_H
#define SCENE_H

#include "event_attorney.h"

namespace pav
{
	/**
	 * \class	IScene
	 *
	 * \brief	Scene interface used to hold all GameObject objects and special partition them with
	 * 			scene graph
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class IScene
	{
	public:
		virtual void BeginScene();
		virtual void EndScene();
		virtual void Update(const float delta_time);

		virtual void SetupEngineEvents(EventAttorney* event_attorney);
	};
}

#endif // SCENE_H
