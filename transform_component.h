#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "core/entity_component/i_component.h"
#include "core/entity_component/i_game_object.h"

namespace pav
{
	/**
	 * \class	TransformComponent
	 *
	 * \brief	A transform component. This class cannot be inherited..
	 *
	 * \author	Jaymie
	 * \date	2/23/2019
	 */
	class TransformComponent final : public IComponent<TransformComponent, 0>
	{
	private:
		// Local transform values
		glm::vec3 position_;
		glm::vec3 rotation_;
		glm::vec3 scale_;

		// Transform matrices and quaternion
		glm::mat4 position_mat4_;
		glm::quat rotation_quat_;
		glm::mat4 scale_mat4_;

	public:

		/**
		 * \fn	TransformComponent::TransformComponent();
		 *
		 * \brief	Default constructor
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 */
		TransformComponent(IGameObjectBase* owner);

		/**
		 * \fn	glm::vec3 TransformComponent::GetPosition() const;
		 *
		 * \brief	Gets the position
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \returns	The position.
		 */
		glm::vec3 GetPosition() const;

		/**
		 * \fn	glm::vec3 TransformComponent::GetRotation() const;
		 *
		 * \brief	Gets the rotation
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \returns	The rotation.
		 */
		glm::vec3 GetRotation() const;

		/**
		 * \fn	glm::vec3 TransformComponent::GetScale() const;
		 *
		 * \brief	Gets the scale
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \returns	The scale.
		 */
		glm::vec3 GetScale() const;

		/**
		 * \fn	void TransformComponent::SetPosition(const glm::vec3& pos);
		 *
		 * \brief	Set transform position
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \param	pos	The position.
		 */
		void SetPosition(const glm::vec3& pos);

		/**
		 * \fn	void TransformComponent::SetRotation(const glm::vec3& rot);
		 *
		 * \brief	Set transform rotation
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \param	rot	The rot.
		 */
		void SetRotation(const glm::vec3& rot);

		/**
		 * \fn	void TransformComponent::SetScale(const glm::vec3& scale);
		 *
		 * \brief	Set transform scale
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \param	scale	The scale.
		 */
		void SetScale(const glm::vec3& scale);
	};
}

#endif // TRANSFORM_COMPONENT_H