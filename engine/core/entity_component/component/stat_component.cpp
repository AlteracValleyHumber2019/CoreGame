#include "pav_pch.h"
#include "stat_component.h"


pav::StatComponent::StatComponent(IGameObjectBase* owner) :
	IComponent<StatComponent, 0>::IComponent(owner)
{

}

void pav::StatComponent::SetCurrentHealth(int newHealth)
{
	currentHealth = newHealth;
}

void pav::StatComponent::SetCurrentMana(int newMana)
{
	currentMana = newMana;
}

constexpr int pav::StatComponent::GetCurrentHealth()
{
	return currentHealth;
}

constexpr int pav::StatComponent::GetCurrentMana()
{
	return currentMana;
}

constexpr int pav::StatComponent::GetMaxHealth()
{
	return maxHealth;
}

constexpr int pav::StatComponent::GetDamage()
{
	return damage;
}

constexpr int pav::StatComponent::GetArmor()
{
	return armor;
}

constexpr int pav::StatComponent::GetMagicResist()
{
	return magicResist;
}

constexpr float pav::StatComponent::GetHitRating()
{
	return hitRating;
}

constexpr float pav::StatComponent::GetDodgeRating()
{
	return dodgeRating;
}

constexpr float pav::StatComponent::GetCritRating()
{
	return critRating;
}

constexpr float pav::StatComponent::GetCritDamage()
{
	return critDamage;
}

constexpr float pav::StatComponent::GetAttackSpeed()
{
	return attackSpeed;
}

constexpr int pav::StatComponent::GetMoveSpeed()
{
	return moveSpeed;
}

void pav::StatComponent::Begin()
{
}

void pav::StatComponent::End()
{
}
