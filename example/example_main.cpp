//! [ExampleMain entry point]

#include "pav_pch.h"
#include "engine/core/engine.h"
#include "scene/example_scene.h"
#include "Trees/CoordNode.h"
#include "Trees/QuadTree.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<pav::Engine> engine = std::make_unique<pav::Engine>();

	engine->SetWindowInfo({ 800, 600, 100, 100, "Project Alterac Valley" });
	engine->InitEngine();

	engine->scene_manager->AddScene("example_scene", std::make_unique<ExampleScene>());
	engine->scene_manager->SwitchScene("example_scene");

	engine->StartEngine();
	std::vector<float> coordinate;
	std::vector<float> topbound;
	std::vector<float> lowbound;
	topbound.push_back(0.0f);
	topbound.push_back(0.0f);
	lowbound.push_back(50.0f);
	lowbound.push_back(50.0f);
	coordinate.push_back(0.0f);
	coordinate.push_back(0.0f); 
	int data = 1;

	pav::QuadTree<int>* tree = new pav::QuadTree<int>(topbound, lowbound);

	for (int i = 0; i < 40; i++) {
		coordinate[1] += 1.0f;
		coordinate[0] += 1.0f;
		pav::CoordNode<int>* node = new pav::CoordNode<int>(coordinate, data);
		tree->InsertNode(node);
	}
	

	return 0;
}

//! [ExampleMain entry point]
