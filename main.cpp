#include "pav_pch.h"
#include "core/engine.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<pav::Engine> engine = std::make_unique<pav::Engine>();
	engine->SetWindowInfo({ 800, 600, 100, 100, "Project Alterac Valley" });
	engine->StartEngine();

	return 0;
}
