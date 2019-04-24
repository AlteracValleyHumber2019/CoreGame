//! [ExampleMain entry point]

#include "pav_pch.h"
#include "engine/core/engine.h"
#include "scene/example_scene.h"

#include "NetworkLib/NetworkLib/DatabaseConnection.h"

int main(int argc, char* argv[])
{
	// Connect to the Database
	//DataBaseConnection dbcon = new DataBaseConnection("remotemysql.com", "xLrH61KxG0", "Ps26I2WARu", "xLrH61KxG0", 3306, true);

	// Create a query
	//string query1 = "SELECT * FROM users;";

	// Call the query
	//MYSQL_RES* res = dbcon.fetchInformation(query1);
	//MYSQL_ROW row;

	//if (row = mysql_fetch_row(res))
	//	cout << row[0] << endl;
	// Confirm Success of Query
	//else
	//	cout << "Invalid Query";

	std::unique_ptr<pav::Engine> engine = std::make_unique<pav::Engine>();

	engine->SetWindowInfo({ 800, 600, 100, 100, "Project Alterac Valley" });
	engine->InitEngine();

	engine->scene_manager->AddScene("example_scene", std::make_unique<ExampleScene>());
	engine->scene_manager->SwitchScene("example_scene");


	engine->StartEngine();


	return 0;
}

//! [ExampleMain entry point]
