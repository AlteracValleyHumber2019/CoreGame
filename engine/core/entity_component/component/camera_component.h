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

	public:
		virtual void Update(const float delta_time) override;

		float GetYaw() const;
		float GetPitch() const;

		void SetYaw(const float value);
		void SetPitch(const float value);
	};
}

#endif // CAMERA_COMPONENT_H