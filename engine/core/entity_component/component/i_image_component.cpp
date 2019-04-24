#include "pav_pch.h"
#include "i_image_component.h"

using namespace pav;

void pav::IImageComponent::SetImage(std::string fileName_)
{
	fileName = fileName_;
}

pav::IImageComponent::IImageComponent(IGameObjectBase* owner) :
	IComponent<IImageComponent, 0>::IComponent(owner)
{
}

void pav::IImageComponent::Begin()
{
}

void pav::IImageComponent::End()
{
}

void pav::IImageComponent::Update(const float delta_time)
{
}

void pav::IImageComponent::SetupEngineEvents(EventAttorney* event_attorney)
{
}

void pav::IImageComponent::Render(TransformComponent* transform)
{
}