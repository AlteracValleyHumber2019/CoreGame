#ifndef EXAMPLE_SCENE_H
#define EXAMPLE_SCENE_H

#include "../../engine/core/i_scene.h"

namespace pav_game
{
	class ExampleScene : public pav::IScene
	{
	public:
		virtual void BeginScene() override;

		virtual void EndScene() override;

		virtual void Update(const float delta_time) override;

		virtual void SetupEngineEvents(pav::EventAttorney* event_attorney) override;

	private:
		void OnKeydown(pav::KeyCode kc);

	};
}

#endif // EXAMPLE_SCENE_h
