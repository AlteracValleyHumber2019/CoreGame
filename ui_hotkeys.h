#ifndef UI_HOTKEYS
#define UI_HOTKEYS

#include "event_attorney.h"
#include "pav_pch.h"
#include "event_util.h"
#include "entity_component/sec_manager.h"
#include "component_manager.h"

using namespace pav {	

	//TODO: inherit from primary UI class
	class ui_hotkeys
	{
	public:
		Vec3 transform;

		pav::ui_hotkeys::ui_hotkeys() : sec_manager_(std::make_unique<SECManager>()) {}

		//initialize hotkeys using event_util enum keys
		ui_hotkeys();

		//set hotkeys to available ui componnents 
		virtual void OnCreate();

		//remove hotkeys from ui componenets
		virtual void OnDestroy();
		
		//adds a IGameObject object, to add ui component
		//setup ui events
		virtual void OnUpdate(const float delta_time);

		//keyboard callback function, to determine keystrokes 
		//opens and closes certain ui using hotkeys
		virtual void OpenUI();
		virtual void CloseUI();		

		//key that is pressed, locations of mouse when key is pressed
		void keyPressed(unsigned char key, int x, int y);

		//key up removes ui from screen
		void keyUp(unsigned char key, int x, int y);

		// Create an array of boolean values of length 256 (0-255)
		bool* keyStates = new bool[256]; 
	};
}

#endif