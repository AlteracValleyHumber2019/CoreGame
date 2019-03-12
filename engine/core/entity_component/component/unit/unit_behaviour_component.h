#ifndef UNIT_BEHAVIOUR_COMPONENT_H
#define UNIT_BEHAVIOUR_COMPONENT_H

#include "../../i_component.h"

namespace pav
{

	/**
	 * \struct	UnitModTracker
	 *
	 * \brief	A unit modifier status tracker. This is used to track data such as mod GUID, current
	 *			stack count, time remain etc.
	 *
	 * \author	Jaymie
	 * \date	3/12/2019
	 */
	struct UnitModTracker
	{

	};

	/**
	 * \class	UnitBehaviourComponent
	 *
	 * \brief	A unit behavior component. This component contains unit FSM as well as unit stat mods
	 *
	 * \author	Jaymie
	 * \date	3/12/2019
	 */
	class UnitBehaviourComponent : public IComponent<UnitBehaviourComponent, 10>
	{
	private:
		// Data section
		/** \brief	The health */
		float health_;

		/** \brief	The resource */
		float resource_;

		// Containers
		/** \brief	Map used to store list of all mods */
		std::unordered_map<unsigned int, UnitModTracker> unit_mods_;

	public:

		virtual void Begin() override;


		virtual void End() override;


		virtual void Update(const float delta_time) override;

	};

}

#endif // UNIT_BEHAVIOUR_COMPONENT_H