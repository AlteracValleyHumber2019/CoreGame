#include "pav_pch.h"
#include "component_manager.h"

void pav::ComponentManager::SetupEngineEvents(EventAttorney* event_attorney)
{
	event_attorney_ = event_attorney;
}
