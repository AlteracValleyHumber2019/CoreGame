#ifndef UNIT_MOD_H
#define UNIT_MOD_H

namespace pav
{

	/**
	 * \struct	IUnitModBooleanCondition
	 *
	 * \brief	Strategy class used to write unit mod exit condition
	 *
	 * \author	Jaymie
	 * \date	3/12/2019
	 */
	struct IUnitModBooleanCondition
	{
		virtual bool Condition(class UnitBehaviourComponent* target, const class UnitModTracker* current_mods) = 0;
	};

	/**
	 * \class	UnitMod
	 *
	 * \brief	A unit modifier. Use this class as base to create your own mod.
	 *
	 * \author	Jaymie
	 * \date	3/12/2019
	 */
	class IUnitMod
	{
	private:
		/** \brief	The exit condition */
		std::unique_ptr<IUnitModBooleanCondition> exit_condition_;

	public:

		/**
		 * \fn	virtual void UnitMod::ApplyMod(class UnitBehaviourComponent* target, const class UnitModTracker* current_mods) = 0;
		 *
		 * \brief	Applies the modifier
		 *
		 * \author	Jaymie
		 * \date	3/12/2019
		 *
		 * \param [in]	target			If non-null, target for the mod.
		 * \param 	  	current_mods	The current mods of this type. NULL if none.
		 */
		virtual void ApplyMod(class UnitBehaviourComponent* target, const class UnitModTracker* current_mods) = 0;

		/**
		 * \fn	virtual void UnitMod::RemoveMod(class UnitBehaviourComponent* target, const class UnitModTracker* current_mods) = 0;
		 *
		 * \brief	Removes the modifier
		 *
		 * \author	Jaymie
		 * \date	3/12/2019
		 *
		 * \param [in]	target			If non-null, target for the mod.
		 * \param 	  	current_mods	The current mods of this type. NULL if none.
		 */
		virtual void RemoveMod(class UnitBehaviourComponent* target, const class UnitModTracker* current_mods) = 0;

		/**
		 * \fn	virtual void UnitMod::Update()
		 *
		 * \brief	Updates this mod
		 *
		 * \author	Jaymie
		 * \date	3/12/2019
		 */
		virtual void Update() {};

		/**
		 * \fn	void UnitMod::ExitCondition();
		 *
		 * \brief	Exit condition of the mod.
		 *
		 * \author	Jaymie
		 * \date	3/12/2019
		 */
		bool ExitCondition(class UnitBehaviourComponent* target, const class UnitModTracker* current_mods);

		/**
		 * \fn	template <typename T> inline void IUnitMod::SetExitConditionStrategy()
		 *
		 * \brief	Sets exit condition strategy
		 *
		 * \tparam	T	IUnitModBooleanCondition based type parameter.
		 */
		template <typename T>
		inline void SetExitConditionStrategy()
		{
			exit_condition_ = std::make_unique<T>();
		}
	};
}

#endif // UNIT_MOD_H