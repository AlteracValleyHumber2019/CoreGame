#ifndef SCENE_H
#define SCENE_H

#include "event_attorney.h"
#include "entity_component/sec_manager.h"

namespace pav
{
	/**
	 * \class	IScene
	 *
	 * \brief	Scene interface used to hold all game play related objects.
	 * 			
	 * The scene is the super container for almost all game play related object.
	 * It has an inner SEC system that managers all \ref IGameObjectBase objects and
	 * \ref IComponentBase objects.
	 * 			
	 * \snippet scene/example_scene.h ExampleScene custom scene
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class IScene
	{
	private:
		std::unique_ptr<SECManager> sec_manager_;

	protected:

		/**
		 * \fn	const SECManager* IScene::GetSECManager();
		 *
		 * \brief	Gets the current system of entity component manager
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \returns	The entity component manager.
		 */
		SECManager* GetSECManager();

	public:
		IScene();

		/**
		 * \fn	virtual void IScene::BeginScene();
		 *
		 * \brief	Scene begin logic
		 *
		 * \author	Jaymie
		 * \date	2/21/2019
		 */
		virtual void BeginScene();

		/**
		 * \fn	virtual void IScene::EndScene();
		 *
		 * \brief	Scene ending logic
		 *
		 * \author	Jaymie
		 * \date	2/21/2019
		 */
		virtual void EndScene();

		/**
		 * \fn	virtual void IScene::Update(const float delta_time);
		 *
		 * \brief	Updates the current scene
		 *
		 * \author	Jaymie
		 * \date	2/21/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		virtual void Update(const float delta_time);

		/**
		 * \fn	virtual void IScene::SetupEngineEvents(EventAttorney* event_attorney);
		 *
		 * \brief	Sets up the engine events
		 * 			
		 * \snippet scene/example_scene.cpp ExampleScene setup event
		 *
		 * \author	Jaymie
		 * \date	2/21/2019
		 *
		 * \param [in]	event_attorney	If non-null, the event attorney.
		 */
		virtual void SetupEngineEvents(EventAttorney* event_attorney);
	};
}

#endif // SCENE_H
