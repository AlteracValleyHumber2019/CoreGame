#include "ui_hotkeys.h"
#include "pav_pch.h"
#include "event_util.h"


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
}

void pav::ui_hotkeys::keyPressed(unsigned char key, int x, int y) {
	//switch case/ if statement for key
}

void pav::ui_hotkeys::CloseUI() {}
