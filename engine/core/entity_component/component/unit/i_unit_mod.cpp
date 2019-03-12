#include "pav_pch.h"
#include "i_unit_mod.h"
#include "unit_behaviour_component.h"

bool pav::IUnitMod::ExitCondition(UnitBehaviourComponent* target, const UnitModTracker* current_mods)
{
	// Check if we have a valid exit condition
	if (exit_condition_ != nullptr)
	{
		return false;
	}

	// Test condition
	return exit_condition_->Condition(target, current_mods);
}
