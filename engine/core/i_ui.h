#ifndef UI_H
#define UI_H

#include "event_attorney.h"
#include "entity_component/sec_manager.h"

namespace pav {
	/**
	 * \class	IUI
	 *
	 * \brief	UI interface used to hold all 2D that'll be used in game
	 *
	 * \author	Matthew
	 * \date	3/9/2019
	 */
	class IUI {
	private:
		std::unique_ptr<SECManager> sec_manager_;
	protected:
		/**
		 * \fn	const SECManager* IScene::GetSECManager();
		 *
		 * \brief	Gets the current system of entity component manager
		 *
		 * \author	Matthew
		 * \date	3/9/2019
		 *
		 * \returns	The entity component manager.
		 */
		SECManager* GetSECManager();
	public:
		IUI();
		/**
		 * \fn	virtual void IUI::BeginScene();
		 *
		 * \brief	Creates UI when called
		 *
		 * \author	Matthew
		 * \date	3/9/2019
		 */
		virtual void BeginScene();
		/**
		 * \fn	virtual void IUI::EndScene();
		 *
		 * \brief	Destroys UI when called
		 *
		 * \author	Matthew
		 * \date	3/9/2019
		 */
		virtual void EndScene();
		/**
		 * \fn	virtual void IUI::Update();
		 *
		 * \brief	Destroys UI when called
		 *
		 * \author	Matthew
		 * \date	3/9/2019
		 */
		virtual void Update(const float delta_time);
		/**
		 * \fn	virtual void IUI::SetupEngineEvents(EventAttorney* event_attorney);
		 *
		 * \brief	Sets up the engine events
		 *
		 * \snippet scene/example_scene.cpp ExampleScene setup event
		 *
		 * \author	Matthew
		 * \date	2/21/2019
		 *
		 * \param [in]	event_attorney	If non-null, the event attorney.
		 */
		virtual void SetupEngineEvents(EventAttorney* event_attorney);
	};
}

#endif // UI_H

