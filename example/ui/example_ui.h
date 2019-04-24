#ifndef EXAMPLE_UI_H
#define EXAMPLE_UI_H

#include "core/i_ui.h"
//! [ExampleUI custom scene]
class ExampleUI : public pav::IUI
{
	// Inherited functions
	virtual void BeginScene() override;

	virtual void EndScene() override;

	virtual void Update(const float delta_time) override;

	virtual void Render() override;

	virtual void SetupEngineEvents(pav::EventAttorney* event_attorney) override;
	// Inherited functions
};
//! [ExampleUI custom scene]
#endif // !EXAMPLE_UI_H

