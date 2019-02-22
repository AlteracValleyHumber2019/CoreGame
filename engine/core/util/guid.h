#ifndef GUID_H
#define GUID_H

namespace pav
{
	/**
	 * \class	GUID
	 *
	 * \brief	A static class used to generate a global unique identifier number for a group of types
	 * 			
	 * GUID is used when ever a type requires a global unique identifier number. This number
	 * will be generated upon the type's first used with the GUID class. You should group
	 * types together using the BaseType template parameter, this should normally be a base
	 * class type for a set of types. Base class type should never need to have a GUID
	 * number.
	 *
	 * \author	Jaymie
	 * \date	2/6/2019
	 *
	 * \tparam	BaseType	Type of the base class type.
	 */
	template <typename BaseType>
	class GUID final
	{
	private:

		/**
		 * \fn	inline static unsigned int GUID::NextID()
		 *
		 * \brief	Next available identifier number
		 *
		 * \author	Jaymie
		 * \date	2/6/2019
		 *
		 * \returns	An unsigned int id.
		 */
		inline static unsigned int NextID()
		{
			static unsigned int id = 0; // Remembers next available id
			return ++id;
		}

	public:

		/**
		 * \fn	template <typename Type> inline static unsigned int GUID::GetID()
		 *
		 * \brief	Gets the identifier number for the type Type. If this was the first time type Type
		 * 			was used with this function, then this class will generate a GUID for it.
		 *
		 * \tparam	Type	Type of the type.
		 *
		 * \returns	The identifier.
		 */
		template <typename Type>
		inline static unsigned int GetID()
		{
			static unsigned int id = NextID(); // Stores type Type's GUID
			return id;
		}
	};
}

#endif // GUID_H