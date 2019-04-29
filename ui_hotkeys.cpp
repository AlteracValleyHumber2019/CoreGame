#include "ui_hotkeys.h"
#include "pav_pch.h"
#include "event_util.h"

#include "sdl_image_component.h"

using namespace pav;

ui_hotkeys::ui_hotkeys()
{
	event_util eu;
}

void pav::ui_hotkeys::OnCreate() {}

void pav::ui_hotkeys::OnDestroy() {}

void pav::ui_hotkeys::OnUpdate(const float delta_time) {
	sec_manager_->Update(delta_time);
}

void pav::ui_hotkeys::OpenUI() {
	glutKeyboardFunc(keyPressed);
	pav::SDLImageComponent::Render(transform);
}

void pav::ui_hotkeys::keyPressed(unsigned char key, int x, int y) {
	//switch case/ if statement for key
	
	//set the state of the current key ot pressed
	keyStates[key] = true;

	if (key == 'z')
	{
		pav::SDLImageComponent::Render(transform.x, transform.y);
	}
	if (key == 'x')
	{
		pav::SDLImageComponent::Render(transform.x, transform.y);
	}
	if (key == 'c')
	{
		pav::SDLImageComponent::Render(transform.x, transform.y);
	}
	if (key == 'v')
	{
		pav::SDLImageComponent::Render(transform.x, transform.y);
	}
	if (key == 'b')
	{
		pav::SDLImageComponent::Render(transform.x, transform.y);
	}
}

void pav::ui_hotkeys::CloseUI() 
{
	glutKeyboardUpFunc(keyUp);
	pav::SDLImageComponent::End();
}

void keyUp(unsigned char key, int x, int y)
{
	//switch case/ if statement for key
	
	// Set the state of the current key to not pressed (close UI)
	keyStates[key] = false;
	
	if (key == 'z')
	{
		pav::SDLImageComponent::End();
	}
	if (key == 'x')
	{
		pav::SDLImageComponent::End();
	}
	if (key == 'c')
	{
		pav::SDLImageComponent::End();
	}
	if (key == 'v')
	{
		pav::SDLImageComponent::End();
	}
	if (key == 'b')
	{
		pav::SDLImageComponent::End();
	}
}