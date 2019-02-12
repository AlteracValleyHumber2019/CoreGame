#ifndef I_MANAGER_H
#define I_MANAGER_H

namespace pav
{
	/**
	 * \class	IManager
	 *
	 * \brief	An interface for all base engine level manager-like class
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class IManager
	{
	public:

		/**
		 * \fn	virtual void IManager::Initialize() = 0;
		 *
		 * \brief	Initializes this engine subsystem
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		virtual void Initialize() = 0;

		/**
		 * \fn	virtual void IManager::End() = 0;
		 *
		 * \brief	Ends this engine subsystem
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		virtual void End() = 0;

		/**
		 * \fn	virtual void IManager::Update(float delta_time) = 0;
		 *
		 * \brief	Function to update this engine subsystem every game loop
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		virtual void Update(const float delta_time) = 0;
	};
}

#endif // I_MANAGER_H
