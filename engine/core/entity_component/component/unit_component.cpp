#include "pav_pch.h"
#include "unit_component.h"


pav::UnitComponent::UnitComponent(IGameObjectBase* owner) : IComponent<UnitComponent, 0>::IComponent(owner)
{
}

void pav::UnitComponent::MoveTowards(glm::vec3 position) {
}

void pav::UnitComponent::Jump() {
}

void pav::UnitComponent::ApplyDamage(float amount) {
}

void pav::UnitComponent::Die() {
}

