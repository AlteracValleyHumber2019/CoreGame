#include "pav_pch.h"
#include "GameState.h"


pav::GameState::GameState()
{
}


pav::GameState::~GameState()
{
}

void pav::GameState::UpdateGameState()
{
	// Break the string into substrings and place inside of an array

	// With the new array, store the first section of the substring into a temp string up to the ":" so "CurrentHealth"

	// Compare the tempstring so that we know what datatype we need to parse the value to.

	// if tempstring = "CurrentHealth", we need to parse to int

	// Remove the text from the delimiter up to and including the :, so "CurrentHealth:", from the string

	// We are left with just the value "100" so lets parse it to int
}
