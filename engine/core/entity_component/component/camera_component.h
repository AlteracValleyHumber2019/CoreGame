#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include "../i_component.h"

namespace pav
{
	class CameraComponent : public IComponent<CameraComponent, 1>
	{
	private:
		// Euler Angles
		float yaw_;
		float pitch_;

		glm::vec3 camera_right_, camera_up_, camera_front_;

		glm::vec3 offset_;

	public:
		CameraComponent(IGameObjectBase* owner) :
			IComponent<CameraComponent, 1>(owner),
			yaw_(-90.f),
			pitch_(0.f),
			camera_right_(0.f),
			camera_up_(0.f),
			camera_front_(glm::vec3(0.f, 0.f, -1.f)),
			offset_(0.f)
		{
		}

		virtual void Update(const float delta_time) override;

		float GetYaw() const;
		float GetPitch() const;

		glm::vec3 GetRight() const;
		glm::vec3 GetUp() const;
		glm::vec3 GetFront() const;

		void SetYaw(const float value);
		void SetPitch(const float value);

		void UpdateCamera();

		void SetOffset(glm::vec3 offset);

		glm::mat4 GetOffset() const;
	};
}

#endif // CAMERA_COMPONENT_H