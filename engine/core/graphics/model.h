#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"

namespace pav {

	struct Model
	{
		/**
		 * \class	Model
		 *
		 * \brief	Model class for Project Alterac Valley
		 *
		 * \author	Gabriel Kalil
		 * \date	3/3/2019
		 *
		 * \section This class holds the structure of meshes for the model.
		 *			It's a data class.
		 */
		std::vector<Mesh> meshes;
	};

}
#endif // !MODEL_H

