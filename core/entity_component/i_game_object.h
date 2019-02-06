#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

namespace pav
{
	class IComponentBase;

	/**
	 * \class	IGameObjectBase
	 *
	 * \brief	Base class for all game objects.
	 * 			
	 * 			This class is meant for game object usage. You should not derive your custom game
	 * 			object from this class. For custom game object deriving, refer to the class
	 * 			IGameObject<CRTP>
	 *
	 * \author	Jaymie
	 * \date	2/6/2019
	 */
	class IGameObjectBase
	{
	private:
		// Data
		std::string name_;
		unsigned int guid_;
		unsigned int order_;

		// Components and children
		std::unordered_map<unsigned int, std::vector<pav::IComponentBase*>> components_;
		std::unordered_map<std::string, pav::IGameObjectBase*> children_;

	public:

		/**
		 * \fn	IGameObjectBase::IGameObjectBase(std::string&& name, const unsigned int guid, unsigned int order);
		 *
		 * \brief	Constructor
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param [in]	name 	The name.
		 * \param 	  	guid 	Unique identifier.
		 * \param 	  	order	The order.
		 */
		IGameObjectBase(std::string&& name, const unsigned int guid, unsigned int order);

		/**
		 * \fn	inline unsigned int IGameObjectBase::GetGUID() const
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
		 * \fn	template <typename C, typename ...Args> inline pav::IComponentBase* IGameObjectBase::AddComponent(Args&& ...args);
		 *
		 * \brief	Adds a component
		 *
		 * \tparam	C	   	Type of the component.
		 * \tparam	...Args	Type of the constructor arguments.
		 * \param [in]	...args	The component constructor arguments.
		 *
		 * \returns	Null if it fails, else a pointer to a pav::IComponentBase.
		 */
		template <typename C, typename ...Args>
		inline pav::IComponentBase* AddComponent(Args&& ...args);

		/**
		 * \fn	template <typename C> inline pav::IComponentBase* IGameObjectBase::GetComponent(const size_t index = 0);
		 *
		 * \brief	Gets a component
		 *
		 * \tparam	C	Type of the component.
		 * \param	index	(Optional) Component index.
		 *
		 * \returns	Null if it fails, else the component.
		 */
		template <typename C>
		inline pav::IComponentBase* GetComponent(const size_t index = 0);

		/**
		 * \fn	template <typename C> inline void IGameObjectBase::RemoveComponent(const size_t index = 0);
		 *
		 * \brief	Removes the component with the type C
		 *
		 * \tparam	C	Type of the c.
		 * \param	index	(Optional) Zero-based index of the.
		 */
		template <typename C>
		inline void RemoveComponent(const size_t index = 0);

		/**
		 * \fn	virtual void IGameObjectBase::Begin()
		 *
		 * \brief	Game object begin logic.
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 */
		virtual void Begin() {};

		/**
		 * \fn	virtual void IGameObjectBase::End()
		 *
		 * \brief	Game object ending logic.
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 */
		virtual void End() {};

		/**
		 * \fn	virtual void IGameObjectBase::Update(const float delta_time) = 0;
		 *
		 * \brief	Updates the given delta_time
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		virtual void Update(const float delta_time) = 0;
	};

	/**
	 * \class	IGameObject
	 *
	 * \brief	An intermediate based class act as a super class for all custom game objects.
	 *
	 * \author	Jaymie
	 * \date	2/6/2019
	 *
	 * \tparam	CRTP	Cruously Recurring Template Pattern; pass your custom game object type here.
	 */
	template <typename CRTP>
	class IGameObject : public IGameObjectBase
	{
	public:

		/**
		 * \fn	explicit IGameObject::IGameObject(std::string&& name, const unsigned int order);
		 *
		 * \brief	Constructor
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \param [in]	name 	The name.
		 * \param 		  	order	The order.
		 */
		explicit IGameObject(std::string&& name, const unsigned int order);
	};

	// Include here

	template <typename C, typename ...Args>
	pav::IComponentBase* pav::IGameObjectBase::AddComponent(Args&& ...args)
	{
		return nullptr;
	}

	template<typename C>
	inline pav::IComponentBase * IGameObjectBase::GetComponent(const size_t index)
	{
		return nullptr;
	}

	template<typename C>
	inline void IGameObjectBase::RemoveComponent(const size_t index)
	{
	}

}

#endif // I_GAME_OBJECT_H