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
		 * \fn	virtual void IUI::OnCreate();
		 *
		 * \brief	Creates UI when called
		 *
		 * \author	Matthew
		 * \date	3/9/2019
		 */
		virtual void OnCreate();
		/**
		 * \fn	virtual void IUI::OnDestroy();
		 *
		 * \brief	Destroys UI when called
		 *
		 * \author	Matthew
		 * \date	3/9/2019
		 */
		virtual void OnDestroy();
		/**
		 * \fn	virtual void IUI::Update();
		 *
		 * \brief	Destroys UI when called
		 *
		 * \author	Matthew
		 * \date	3/9/2019
		 */
		virtual void Update(const float delta_time);
	};
}

#endif // UI_H

