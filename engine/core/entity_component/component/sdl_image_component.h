#ifndef SDL_IMAGE_COMPONENT_H
#define SDL_IMAGE_COMPONENT_H

#include "pav_pch.h"
#include "i_image_component.h"

#include <SDL/SDL.h>

namespace pav
{
	/**
	 * \class	SDLImageComponent
	 *
	 * \brief	A image component for UI. This class cannot be inherited..
	 *
	 * \author	Matthew
	 * \date	2/23/2019
	 */
	class SDLImageComponent final : public IImageComponent
	{
	private:
		std::string fileName;
		SDL_Surface *image;
		SDL_Rect rect;

	public:
		SDLImageComponent(IGameObjectBase* owner);

		void SetImage(std::string fileName_);

		virtual void Begin() override;

		virtual void End() override;

		virtual void Update(const float delta_time) override;

		virtual void SetupEngineEvents(EventAttorney* event_attorney) override;

		virtual void Render(TransformComponent* transform);
	};
}

#endif // !IMAGE_COMPONENT_H

