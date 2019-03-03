#ifndef TEXTURE_H
#define TEXTURE_H

#include <queue>
namespace pav {

	struct Texture
	{
		/**
		 * \class	Texture
		 *
		 * \brief	Texture class for Project Alterac Valley
		 *
		 * \author	Gabriel Kalil
		 * \date	3/3/2019
		 *
		 * \section This class will hold the structure for the number of textures to be used
		 *			on a model.
		 */
		std::queue<unsigned int> textures;
	};
}


#endif // TEXTURE_H