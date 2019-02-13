#include "pav_pch.h"
#include "game_object_manager.h"

void pav::GameObjectManager::RemoveGameObject(std::string&& name)
{
	// Check if we have GameObject with name
	if (game_objects_.find(name) != game_objects_.end())
	{
		//Remove DFS
		std::function<void(IGameObjectBase*)> rm_dfs =
			[&game_objects_ = game_objects_, &rm_dfs](IGameObjectBase* go)->void
		{
			for (auto c_go : go->children_)
			{
				// Hopefully no stack overflow
				// well its not like anyone would make a massive
				// GameObject tree just for fun right? right?
				rm_dfs(c_go.second);
			}

			game_objects_.erase(go->name_); // Remove node
		};

		rm_dfs(game_objects_.at(std::move(name)).get());
	}
}

void pav::GameObjectManager::Update(float delta_time)
{
	// Update each GameObject
	for (auto& go : game_objects_)
	{
		go.second->Update(delta_time);
	}
}

void pav::GameObjectManager::SetupEngineEvents(EventAttorney* event_attorney)
{
	event_attorney_ = event_attorney;
}
