#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "i_ui.h"
#include "i_manager.h"
#include "event_attorney.h"

namespace pav
{
	class UIManager : public IManager
	{
	private:
		std::unordered_map<std::string, std::unique_ptr<IUI>> uis_;
		IUI* current_ui_;

		EventAttorney* event_attorney_;
	public:
		void Initialize() override;
		void End() override;
		void Update(const float delta_time) override;

		IUI* AddUI(std::string&& Name, std::unique_ptr<IUI>&& ui);
		IUI* GetUI(std::string&& Name);

		void RemoveUI(std::string&& Name);
		void SwitchUI(std::string&& Name);
		void SetupEngineEvents(EventAttorney* event_attorney);
	};
}

#endif // !UIMANAGER_H