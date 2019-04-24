#include "pav_pch.h"
#include "sdl_image_component.h"

#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

using namespace pav;

void pav::SDLImageComponent::SetImage(std::string fileName_)
{
	fileName = fileName_;
}

pav::SDLImageComponent::SDLImageComponent(IGameObjectBase* owner) : IImageComponent(owner)
{
}

void pav::SDLImageComponent::Begin()
{
	image = SDL_LoadBMP(fileName.c_str());
}

void pav::SDLImageComponent::End()
{
	if (image != nullptr) {
		delete image;
		image = nullptr;
	}
}

void pav::SDLImageComponent::Update(const float delta_time) {}

void pav::SDLImageComponent::SetupEngineEvents(EventAttorney* event_attorney) {}

void pav::SDLImageComponent::Render(TransformComponent* transform) {
	SDL_Surface* screen = SDL_GetWindowSurface(SDL_GL_GetCurrentWindow());

	rect.h = image->h;
	rect.w = image->w;
	rect.x = transform->GetPosition().x;
	rect.y = transform->GetPosition().y;

	SDL_BlitSurface(image, nullptr, screen, &rect);
	SDL_FreeSurface(image);
	SDL_UpdateWindowSurface(SDL_GL_GetCurrentWindow());
}