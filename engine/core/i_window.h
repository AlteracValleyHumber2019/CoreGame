#ifndef I_WINDOW_H
#define I_WINDOW_H

namespace pav
{
	/**
	 * \struct	WindowInfo
	 *
	 * \brief	Information about a window.
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	struct WindowInfo
	{
		size_t      width, height;
		size_t      pos_x, pos_y;
		std::string title;

		/**
		 * \fn	WindowInfo(const size_t width, const size_t height, const size_t pos_x, const size_t pos_y, std::string&& title) : width(width), height(height), pos_x(pos_x), pos_y(pos_y), title(std::move(title))
		 *
		 * \brief	Constructor
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param 	  	width 	The width.
		 * \param 	  	height	The height.
		 * \param 	  	pos_x 	The position x coordinate.
		 * \param 	  	pos_y 	The position y coordinate.
		 * \param [in]	title 	The title.
		 */
		WindowInfo(const size_t  width, const size_t height, const size_t pos_x, const size_t pos_y,
		           std::string&& title) :
			width(width),
			height(height),
			pos_x(pos_x),
			pos_y(pos_y),
			title(std::move(title))
		{
		}

		WindowInfo(const size_t  width, const size_t height, const size_t pos_x, const size_t pos_y,
			const std::string& title) :
			width(width),
			height(height),
			pos_x(pos_x),
			pos_y(pos_y),
			title(title)
		{
		}

		WindowInfo Prototype()
		{
			return WindowInfo(width, height, pos_y, pos_y, title);
		}
	};

	/**
	 * \class	IWindow
	 *
	 * \brief	Interface for a window
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class IWindow
	{
	public:

		/**
		 * \fn	virtual void IWindow::CreateWindow() = 0;
		 *
		 * \brief	Creates a window
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		virtual void CreateWindow(WindowInfo&& win_info) = 0;

		/**
		 * \fn	virtual void IWindow::DestroyWindow() = 0;
		 *
		 * \brief	Destroys this window
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		virtual void DestroyWindow() = 0;

		/**
		 * \fn	virtual void IWindow::SetAsContext() = 0;
		 *
		 * \brief	Set current window as the context for event api and rendering api
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 */
		virtual void SetAsContext() = 0;

		/**
		 * \fn	virtual void IWindow::Update(const float delta_time) = 0;
		 *
		 * \brief	Updates the window
		 *
		 * \author	Jaymie
		 * \date	2/2/2019
		 *
		 * \param	delta_time	The delta time.
		 */
		virtual void Update(const float delta_time) = 0;
	};
}

#endif // I_WINDOW_H
