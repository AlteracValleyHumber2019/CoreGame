#ifndef MATERIAL_H
#define MATERIAL_H


namespace pav {
	struct Material {

		/**
		 * \class	Material
		 *
		 * \brief	Material class for Project Alterac Valley
		 *
		 * \author	Gabriel Kalil
		 * \date	4/8/2019
		 *
		 * \section This class will hold the structure for the material elements.
		 */

		Material() = default;
		~Material() = default;

		glm::vec3 specular;
		float shine;

		glm::vec3 light_ambient;
		glm::vec3 light_diffuse;
		glm::vec3 light_specular;
	};
}
#endif // !MATERIAL_H
