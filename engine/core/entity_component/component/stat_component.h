#ifndef STAT_COMPONENT_H
#define STAT_COMPONENT_H

#include "../i_component.h"
#include "../i_game_object.h"

namespace pav
{
	/**
		 * \class	StatComponent
		 *
		 * \brief	A stat component. Contains access to character stats which will be used for calculating damage, health. ect..
		 * At some point these values may read in from a file or database. For now they are fine from this class.
		 *
		 * \author	Landon
		 * \date	3/10/2019
	 */
	class StatComponent : public IComponent<StatComponent, 0>
	{
	private:
		/* Uncomment if these base values are required at some point. For example, if we cannot get the stats from database first (Fall Back)
		// Base Values for any character. After these are used, character specific stats will be loaded on top
		const int BASE_HEALTH = 1000;			// Minimum Health any character can start with, Character dies if this reaches 0
		const int BASE_MANA = 100;				// Minimum Mana any character can start with, Allows the character to uses abilities
		const int BASE_DAMAGE = 50;				// Minimum Damage any character can start with, Determines Auto Attack Damage and Ability Damage
		const int BASE_ARMOR = 30;				// Minimum Armor any character can start with, Reduces incoming Physical Damage
		const int BASE_MAGIC_RESIST = 20;		// Minimum Magic Resist any character can start with, Reduces incoming Magical Damage
		const float BASE_HIT_RATING = 90;		// Minimum Hit Rating any character can start with, Determines chance to hit with Auto Attacks and Abilities, Decreased by Dodge
		const float BASE_DODGE_RATING = 5;		// Minimum Dodge Rating any character can start with, Determines chance to avoid damage from Auto Attacks and Abilities
		const float BASE_CRITICAL_RATING = 5;	// Minimum Critical Rating any character can start with, Determines chance to add Critical Damage on to Auto Attack or Abilities
		const float BASE_CRITICAL_DAMAGE = 80;	// Minimum Critical Damage any character can start with, Determines how much bonus damage is added on Auto Attacks or Abilities when Critical is Successful (80 = +80% damage)
		const int BASE_MOVEMENT_SPEED = 300;	// Minimum Movement Speed any character can start with, Determines how fast the character can move in any direction
		const float BASE_ATTACK_SPEED = 0.7f;	// Minimum Attack Speed any character can start with, Determines the number of auto attacks per second that a character can do
		*/

		// Total Character Stats after added to Base
		int currentHealth;
		int maxHealth;
		int damage;
		int armor;
		int magicResist;
		float hitRating;
		float dodgeRating;
		float critRating;
		float critDamage;
		int moveSpeed;
		float attackSpeed;

	public:
		StatComponent(IGameObjectBase* owner);

		constexpr int GetCurrentHealth();
		constexpr int GetMaxHealth();
		constexpr int GetDamage();
		constexpr int GetArmor();
		constexpr int GetMagicResist();
		constexpr float GetHitRating();
		constexpr float GetDodgeRating();
		constexpr float GetCritRating();
		constexpr float GetCritDamage();
		constexpr float GetAttackSpeed();
		constexpr int GetMoveSpeed();

		virtual void Begin() override;

		virtual void End() override;
	};
}
#endif // STAT_COMPONENT_H
