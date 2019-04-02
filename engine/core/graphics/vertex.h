#ifndef VERTEX_H
#define VERTEX_H


namespace pav {
	struct Vertex
	{
		/**
		 * \class	Vertex
		 *
		 * \brief	Vertex class for Project Alterac Valley
		 *
		 * \author	Gabriel Kalil
		 * \date	3/3/2019
		 *
		 * \section This class holds the vertex and texture position values.
		 *			It's a data class.
		 */

		glm::vec3 position;
		glm::vec2 texture_position;
		glm::vec3 normal;
		glm::vec3 tangent;
		glm::vec3 bitangent;
	};


}

#endif // VERTEX_H