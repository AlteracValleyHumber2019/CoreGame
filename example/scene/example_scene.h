#ifndef EXAMPLE_SCENE_H
#define EXAMPLE_SCENE_H

#include "core/i_scene.h"
//! [ExampleScene custom scene]
class ExampleScene : public pav::IScene
{
public:
	// Inherited functions
	virtual void BeginScene() override;


	virtual void EndScene() override;


	virtual void Update(const float delta_time) override;


	virtual void SetupEngineEvents(pav::EventAttorney* event_attorney) override;
	// Inherited functions


	// Custom function used for a keydown event handle
	void OnKeydown(pav::KeyCode keycode);

};
//! [ExampleScene custom scene]

#endif // EXAMPLE_SCENE_H

