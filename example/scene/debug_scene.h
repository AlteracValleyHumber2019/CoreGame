#ifndef DEBUG_SCENE_H
#define DEBUG_SCENE_H

#include "core/i_scene.h"
#include "core/dependent/resource/model_resource.h"
#include "core/dependent/resource/i_shader_resource.h"

class DebugScene : public pav::IScene
{
private:
	WindowType* win;

	std::unique_ptr<pav::ModelResource> model_res_;

	std::unique_ptr<pav::IShaderResource> shader_res_;

public:

	virtual void BeginScene(WindowType* win) override;


	virtual void EndScene() override;


	virtual void Update(const float delta_time) override;


	virtual void SetupEngineEvents(pav::EventAttorney* event_attorney) override;

};

#endif // DEBUG_SCENE_H