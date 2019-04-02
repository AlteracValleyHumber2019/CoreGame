#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "entity_component/character.h"

namespace pav
{
	/**
 * \class	GameState
 *
 * \brief	Class for data sent and recieve through network
 *
 * An easy place to package data that is sent and recieved from the network
 * 
 * 
 *
 * \author	Landon
 * \date	3/22/2019
 */
	
	
	class GameState
	{
	private:
		std::vector<character> characters;		// Stores all characters in game (or maybe in section)

		// The below lines are commented out to avoid errors. These classes will be added in the next sprint

		// std::vector<graveyard> graveyards;	// Stores all graveyards in game
		// std::vector<unit> units;				// Stores all NPC and Enemy units/bosses in game (or maybe in section)

	public:
		GameState();
		~GameState();

		void UpdateGameState(); // This method will take in the JSON or String and will break the string into substrings based on delimiter and store into an array.
		// With the newly created array we can iterate through each index and parse the value to the appropiate primative type.

		// TODO: Discuss with the gameplay team, how do we want to handle getting information from the GameState
		// That implementation will be here.
	};

}
#endif
