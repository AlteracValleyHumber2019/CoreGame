#ifndef I_IMAGE_COMPONENT_H
#define I_IMAGE_COMPONENT_H

#include "pav_pch.h"
#include "../i_component.h"
#include "../i_game_object.h"
#include "transform_component.h"

namespace pav
{
	/**
	 * \class	IImageComponent
	 *
	 * \brief	A image component for UI. This class can be inherited
	 *
	 * \author	Matthew
	 * \date	4/23/2019
	 */
	class IImageComponent : public IComponent<IImageComponent, 0>
	{
	private:
		std::string fileName;

	public:
		/**
		 * \fn	IImageComponent::TransformComponent(IGameObjectBase* owner);
		 *
		 * \brief	Default constructor
		 *
		 * \author	Matthew
		 * \date	4/23/2019
		 *
		 * \param [in]	owner	If non-null, the owner.
		 */
		IImageComponent(IGameObjectBase* owner);

		/**
		 * \fn	SetImage(std::string fileName_);
		 *
		 * \brief	Set the filename
		 *
		 * \author	Matthew
		 * \date	4/23/2019
		 */
		void SetImage(std::string fileName_);

		virtual void Begin() override;

		virtual void End() override;

		virtual void Update(const float delta_time) override;

		virtual void SetupEngineEvents(EventAttorney* event_attorney) override;

		virtual void Render(TransformComponent* transform);
	};
}
#endif // !I_IMAGE_COMPONENT_H
