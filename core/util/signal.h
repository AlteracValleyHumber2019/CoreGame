#ifndef SIGNAL_H
#define SIGNAL_H

namespace pav
{
	/**
	 * \class	Signal
	 *
	 * \brief	A signal and slots delegate system
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 *
	 * \tparam	...Args	list of all function parameters used in the delegated function
	 */
	template <typename ...Args>
	class Signal
	{
	private:
		std::unordered_map<unsigned int, std::function<Args...>> slots_;

	public:
		inline unsigned Connect(std::function<Args...>& slot)
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
