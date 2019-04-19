#ifndef DEBUG_SCENE_H
#define DEBUG_SCENE_H

#include "core/i_scene.h"
#include "core/dependent/resource/model_resource.h"
#include "core/dependent/resource/i_shader_resource.h"
#include "core/dependent/opengl/gl_renderable_object.h"
#include "core/entity_component/i_game_object.h"

class DebugScene : public pav::IScene
{
private:
	WindowType* win;
	std::unique_ptr<pav::ModelResource> model_res_;
	std::unique_ptr<pav::ModelResource> model_res_projectile;

	std::unique_ptr<pav::IShaderResource> shader_res_;

	std::unique_ptr<pav::GLRenderableObject> object_;
	std::unique_ptr<pav::GLRenderableObject> object_Projectile;

public:

	virtual void BeginScene(WindowType* win) override;


	virtual void EndScene() override;


	virtual void Update(const float delta_time) override;


	virtual void SetupEngineEvents(pav::EventAttorney* event_attorney) override;

	void OnKeyHold(pav::KeyCode keycode);

};

#endif // DEBUG_SCENE_H