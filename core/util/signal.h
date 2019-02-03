#ifndef SIGNAL_H
#define SIGNAL_H

namespace pav
{
	/** \brief	Signature of a generic pointer to member function */
	template <typename O, typename R, typename ...Args>
	using MemberFunction = R(O::*)(Args...);

	/** \brief	Object type of any */
	using MemberObjectType = void*;

/**
 * \def	MEMBER_FUNC_TYPE
 *
 * \brief	Signature of a template version of pointer to member function
 *
 * \author	Jaymie
 * \date	2/2/2019
 */
#define MEMBER_FUNC_TYPE MemberFunction<O, R, Args...>

	/**
	 * \struct	MemberFunctionCallback
	 *
	 * \brief	Wrapper struct for storing a pointer to a member function
	 * 			
	 * 			MemberFunctionCallback stores pointer to a member function. it is instantiated with a
	 * 			member function's object type, return type and all of its argument types.
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 *
	 * \tparam	O	   	Object that owns the member function.
	 * \tparam	R	   	Return type of the function.
	 * \tparam	...ARGS	Last of arguments.
	 */
	template <typename O, typename R, typename ...Args>
	struct MemberFunctionCallback
	{
	private:
		MemberObjectType member_object_;    // Object that owns the member function
		MEMBER_FUNC_TYPE mfc_;              // A pointer to member function

	public:
		explicit inline MemberFunctionCallback(MemberObjectType object, MEMBER_FUNC_TYPE mfc) :
			member_object_(object),
			mfc_(mfc)
		{
		}

		inline R Invoke(Args&& ...args)
		{
			return (static_cast<O*>(member_object_)->*mfc_)(std::forward<Args>(args)...);
		}
	};

	/**
	 * \struct	DelegateBase
	 *
	 * \brief	A base wrapper class for storing semi generic Delegate objects
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 *
	 * \tparam	R	   	The return type of the callback member function
	 * \tparam	...Args	The parameters types of the callback member function
	 */
	template <typename R, typename ...Args >
	struct DelegateBase
	{
		virtual ~DelegateBase() = default;
		virtual R Invoke(Args&& ...args) = 0;
	};

	/**
	 * \class	Delegate
	 *
	 * \brief	A container for storing an callback function
	 * 			
	 * 			Delegate can registers a member function. The function pointer is stored here and can
	 * 			be invoked at any time by a caller.
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 *
	 * \tparam	O	   	The member function's class/struct
	 * \tparam	R	   	The return type of the callback member function
	 * \tparam	...Args	The parameters types of the callback member function
	 */
	template <typename O, typename R, typename ...Args>
	class Delegate : public DelegateBase<R, Args...>
	{
	private:
		std::unique_ptr<MemberFunctionCallback<O, R, Args...>> callback_;

	public:

		/**
		 * \fn	inline Delegate::Delegate() = default;
		 *
		 * \brief	Default constructor
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		inline Delegate() = default;

		/**
		 * \fn	inline void Delegate::Register(MemberObjectType object, MEMBER_FUNC_TYPE func)
		 *
		 * \brief	Register a member function as a callback function
		 * 			
		 * 			Register takes a class/struct's member function and assigns it as a callback
		 * 			function. The registration involves a pointer to a object and a pointer to a member
		 * 			function.
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param	object	The member function's object.
		 * \param	func  	The member function to be assigned as a callback function.
		 */
		inline void Register(MemberObjectType object, MEMBER_FUNC_TYPE func)
		{
			callback_ = std::make_unique<MemberFunctionCallback<O, R, Args...>>(object, func);
		}

		/**
		 * \fn	inline R Delegate::Invoke(Args&& ...args) override
		 *
		 * \brief	Calls the call back function registered by Register(MemberObjectType,
		 * 			MEMBER_FUNC_TYPE)
		 * 			
		 * 			Invokes the previously registered function. Client should also provide all required
		 * 			arguments of the function. The function HasCallback() should be called to check if
		 * 			this Delegate has any callback function before using this function.
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param [in,out]	...args	The required arguments of the function
		 *
		 * \returns	The return type of the callback function
		 */
		inline R Invoke(Args&& ...args) override
		{
			return callback_->Invoke(std::forward<Args>(args)...);
		}

		/**
		 * \fn	inline bool Delegate::HasCallback() const
		 *
		 * \brief	Check if this Delegate has a callback function assigned
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \returns	True if callback, false if not.
		 */
		inline bool HasCallback() const
		{
			return callback_ != nullptr;
		}
	};

	/**
	 * \class	Signal
	 *
	 * \brief	A signal and slots delegate system
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 *
	 * \tparam	R	   	The return type of the callback slot function
	 * \tparam	...Args	list of all function parameters used in the delegated function.
	 */
	template <typename R, typename ...Args>
	class Signal
	{
	private:
		std::unordered_map<unsigned int, std::unique_ptr<DelegateBase<R, Args...>>> slots_;

	public:
		inline unsigned Connect(std::unique_ptr<DelegateBase<R, Args...>>&& slot)
		{
			return 0;
		}

		inline void Disconnect(const unsigned int id)
		{
			
		}

		inline void EmitAll(Args&& ...args)
		{
			
		}
	};

}

#endif // SIGNAL_H
