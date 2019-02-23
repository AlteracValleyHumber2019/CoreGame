#ifndef I_COMPONENT_H
#define I_COMPONENT_H

#include "../event_attorney.h"
#include "../util/guid.h"

namespace pav
{
	class IGameObjectBase;

	/**
	 * \class	IComponentBase
	 *
	 * \brief	A component base.
	 *
	 * \author	Jaymie
	 * \date	2/6/2019
	 */
	class IComponentBase
	{
	private:
		unsigned int guid_;
		unsigned int order_;

	protected:
		/** \brief	The owner */
		IGameObjectBase* owner_;

		/** \brief	True if is active, false if not */
		bool is_active_;

		/** \brief	True to ignore automatic update */
		bool ignore_auto_update_;

	public:
		IComponentBase(const unsigned int guid, const unsigned int order, IGameObjectBase* owner);

		/**
		 * \fn	inline unsigned int IComponentBase::GetGUID() const
		 *
		 * \brief	Getter for the unique identifier
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \returns	The unique identifier.
		 */
		inline unsigned int GetGUID() const
		{
			return guid_;
		}

		/**
		 * \fn	inline unsigned int IComponentBase::GetOrder() const
		 *
		 * \brief	Gets the order
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \returns	The order.
		 */
		inline unsigned int GetOrder() const
		{
			return order_;
		}

		/**
		 * \fn	IGameObjectBase* IComponentBase::GetOwner();
		 *
		 * \brief	Gets the game object owner of this item
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \returns	The owner.
		 */
		IGameObjectBase* GetOwner();

		/**
		 * \fn	inline bool IComponentBase::IsActive() const
		 *
		 * \brief	Query if this component is active
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \returns	True if active, false if not.
		 */
		inline bool IsActive() const
		{
			return is_active_;
		}

		/**
		 * \fn	inline bool IComponentBase::IsIgnoringAutoUpdate() const
		 *
		 * \brief	Query if this component is ignoring automatic update
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \returns	True if ignoring automatic update, false if not.
		 */
		inline bool IsIgnoringAutoUpdate() const
		{
			return ignore_auto_update_;
		}

		/**
		 * \fn	virtual void IComponentBase::SetActive(const bool active);
		 *
		 * \brief	Sets an active
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param	active	True to active.
		 */
		virtual void SetActive(const bool active);

		/**
		 * \fn	virtual void IComponentBase::SetIgnoreAutoUpdate(const bool ignore);
		 *
		 * \brief	Sets ignore automatic update
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param	ignore	True to ignore.
		 */
		virtual void SetIgnoreAutoUpdate(const bool ignore);

		/**
		 * \fn	virtual void IComponentBase::Begin()
		 *
		 * \brief	Begin logic for this object
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 */
		virtual void Begin() {};

		/**
		 * \fn	virtual void IComponentBase::End()
		 *
		 * \brief	Ends logic for this object
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 */
		virtual void End() {};

		/**
		 * \fn	virtual void IComponentBase::Update(const float delta_time) = 0;
		 *
		 * \brief	Updates logic for this component
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		virtual void Update(const float delta_time) = 0;

		/**
		 * \fn	virtual void IComponentBase::SetupEngineEvents(EventAttorney* event_attorney)
		 *
		 * \brief	Sets up the engine events
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param [in]	event_attorney	If non-null, the event attorney.
		 */
		virtual void SetupEngineEvents(EventAttorney* event_attorney) {};
	};

	/**
	 * \class	IComponent
	 *
	 * \brief	A component.
	 *
	 * \author	Jaymie
	 * \date	2/6/2019
	 *
	 * \tparam	CRTP 	Cruously Recurring Template Pattern; pass your custom component object type
	 * 					here.
	 * \tparam	Order	Order of your custom component.
	 */
	template <typename CRTP, unsigned int Order>
	class IComponent : public IComponentBase
	{
	public:
		IComponent(IGameObjectBase* owner) :
			IComponentBase(pav::GUID<IComponentBase>::GetID<CRTP>(), Order, owner) // CRTP type GUID generation code
		{
		}
	};
}

#endif // I_COMPONENT_H

