#ifndef RESOURCE_H
#define RESOURCE_H

namespace pav
{
	/**
	 * \struct	IResourceBase
	 *
	 * \brief	A resource base.
	 *
	 * \author	Jaymie
	 * \date	2/19/2019
	 */
	struct IResourceBase
	{
	private:
		unsigned int guid_;

	public:
		IResourceBase(const unsigned int guid);

		/**
		 * \fn	unsigned int GetGUID() const;
		 *
		 * \brief	Gets the unique identifier
		 *
		 * \author	Jaymie
		 * \date	2/19/2019
		 *
		 * \returns	The unique identifier.
		 */
		unsigned int GetGUID() const;
	};

	/**
	 * \struct	Resource
	 *
	 * \brief	A resource.
	 *
	 * \author	Jaymie
	 * \date	2/19/2019
	 *
	 * \tparam	CRTP	   	Curiously recurring template pattern for GUID.
	 * \tparam	Data	   	Type of the raw resource.
	 * \tparam	...LoadArgs	Type of the arguments needed to load this resource.
	 */
	template <typename CRTP, typename Data, typename ...LoadArgs>
	struct Resource : public IResourceBase
	{
	public:
		Resource();

		/**
		 * \fn	virtual Data GetData() = 0;
		 *
		 * \brief	Gets the data
		 *
		 * \author	Jaymie
		 * \date	2/19/2019
		 *
		 * \returns	The data.
		 */
		virtual Data GetData() = 0;

		/**
		 * \fn	virtual Data GetData() const = 0;
		 *
		 * \brief	Gets the data
		 *
		 * \author	Jaymie
		 * \date	2/19/2019
		 *
		 * \returns	The data.
		 */
		virtual Data GetData() const = 0;

		/**
		 * \fn	virtual bool Load(LoadArgs&& args...) = 0;
		 *
		 * \brief	Loads a resource of type Data
		 *
		 * \author	Jaymie
		 * \date	2/19/2019
		 *
		 * \param [in]	args...	The arguments necessary to load the resource
		 *
		 * \returns	True if it succeeds, false if it fails.
		 */
		virtual bool Load(LoadArgs&& ...args) = 0;
	};
}

#endif // RESOURCE_H
