#ifndef DEBUG_SCENE_H
#define DEBUG_SCENE_H

#include "core/i_scene.h"

class DebugScene : public pav::IScene
{
private:
	WindowType* win;

public:

	virtual void BeginScene(WindowType* win) override;


	virtual void EndScene() override;


	virtual void Update(const float delta_time) override;


	virtual void SetupEngineEvents(pav::EventAttorney* event_attorney) override;

};

#endif // DEBUG_SCENE_H