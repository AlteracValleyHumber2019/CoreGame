#ifndef I_TEXTURE_H
#define I_TEXTURE_H
#include <string>
#include <vector>

namespace pav{
	class ITexture {

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

	public:
		ITexture(unsigned int texture_id);

		//[BP] added Variables for textures
		unsigned int id;
		std::string type;
		std::string path;
		virtual void UseTexture() = 0;
	};
}


#endif // I_TEXTURE_H