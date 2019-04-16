#include "pav_pch.h"
#include "stat_component.h"


pav::StatComponent::StatComponent(IGameObjectBase* owner) :
	IComponent<StatComponent, 0>::IComponent(owner)
{
}

void pav::StatComponent::SetStat(std::string statName, float newValue) {
	//Set the stat given to the given value. If the stats map doesn't contain the given statName, and new is created
	stats[statName] = newValue;
}

const float pav::StatComponent::GetStat(std::string statName) {
	return stats[statName];
}

void pav::StatComponent::Begin()
{
}

void pav::StatComponent::End()
{
}
