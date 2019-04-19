#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include "i_texture.h"

namespace pav {
	struct Mesh
	{
		Mesh() = default;

		Mesh(const Mesh& mesh)
		{
			vertices = mesh.vertices;
			indices = mesh.indices;
		}
		/**
		 * \class	Mesh
		 *
		 * \brief	Mesh class for Project Alterac Valley
		 *
		 * \author	Gabriel Kalil
		 * \date	3/3/2019
		 *
		 * \section This class will hold the structure for the mesh vertices.
		 */

		std::vector<Vertex> vertices;
		std::unique_ptr<ITexture> texture;
		std::vector<unsigned int> indices;
	};
}

#endif //MESH_H