#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "i_manager.h"
#include "i_window.h"

namespace pav
{
	/**
	 * \class	WindowManager
	 *
	 * \brief	Manager class for windows.
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class WindowManager : public IManager
	{
	private:
		std::unique_ptr<IWindow> window_;

	public:
		WindowManager(std::unique_ptr<IWindow>&& window);

		void Initialize() override;
		void End() override;
		void Update(const float delta_time) override;

		void MakeWindow(WindowInfo&& window_info);
	};
}

#endif // WINDOW_MANAGER_H