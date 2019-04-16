#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "../i_component.h"
#include "../i_game_object.h"

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
		glm::mat4 rotation_mat4_;
		glm::mat4 scale_mat4_;

	public:

		/**
		 * \fn	TransformComponent::TransformComponent(IGameObjectBase* owner);
		 *
		 * \brief	Default constructor
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \param [in]	owner	If non-null, the owner.
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

		glm::mat4 GetPosMatrix() const;

		glm::mat4 GetRotMatrix() const;

		glm::mat4 GetScaleMatrix() const;

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
		 * \fn	void TransformComponent::SetRotation(const glm::vec3& euler);
		 *
		 * \brief	Set transform rotation with euler angle
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \param	euler	The euler angle.
		 */
		void SetRotation(const glm::vec3& euler);

		/**
		 * \fn	void TransformComponent::SetRotation(const glm::vec3& axis, const float angle);
		 *
		 * \brief	Sets a rotation
		 *
		 * \author	Jaymie
		 * \date	2/23/2019
		 *
		 * \param	axis 	The axis, this vector should be between 0 to 1.
		 * \param	angle	The angle in radiants.
		 */
		void SetRotation(const glm::vec3& axis, const float angle);

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

		virtual void Begin() override;

		virtual void End() override;

		virtual void Update(const float delta_time) override;

		virtual void SetupEngineEvents(EventAttorney* event_attorney) override;

	};
}

#endif // TRANSFORM_COMPONENT_H