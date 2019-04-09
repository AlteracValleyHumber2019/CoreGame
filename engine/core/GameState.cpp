#include "pav_pch.h"
#include "GameState.h"


pav::GameState::GameState()
{
}


pav::GameState::~GameState()
{
}

void pav::GameState::UpdateGameState(int characterID, std::string s)
{
	// Break the string into substrings and place inside of an array
	//std::istringstream iss(s);
	//std::vector<std::string> results ((std::istream_iterator<std::string>(iss)))

	// At "|" this is a new entry with key and value
	// At ":" we seperate the value
	std::string splitDelimiter = "|";
	std::string valueDelimiter = ":";

	size_t pos = 0;
	std::string token;

	std::vector<std::string> stateKey;
	std::vector<std::string> stateValue;

	std::cout << "Character " << characterID << "     <--The Character we are retrieving" << std::endl << std::endl;
	std::cout << s << "     <--The String retrieved" << std::endl << std::endl;

	while ((pos = s.find(splitDelimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);

		// Write to console
		std::cout << token << "     <--The Chunk" << std::endl << std::endl;


		size_t subPos = 0;
		std::string subToken;
		while ((subPos = token.find(valueDelimiter)) != std::string::npos)
		{
			subToken = token.substr(subPos + valueDelimiter.length());
			token = token.substr(0, subPos);

			// Print to console
			std::cout << "Key:  " << token << "  Value:  " << subToken << "     <--The Chunk broken down" << std::endl << std::endl << std::endl;
		}

		// Store in stateInformation
		stateKey.push_back(token);
		stateValue.push_back(subToken);

		// Remove delimiter from the string
		s.erase(0, pos + splitDelimiter.length());
	}

	// Write all the information
	for (size_t i = 0; i < stateKey.size(); i++)
	{
		std::string k = stateKey.at(i);
		std::string v = stateValue.at(i);
		std::cout << k << ": " << v << "   ";
		character* thisUnit = characters.at(characterID);

		// Update the Position of the Character
		if (k == "Position")
		{			
			glm::vec3 position;
			size_t vecPos;
			std::string vecToken;

			// The string probably needs to look like "n,n,n," not "n,n,n" but not 100% sure
			while ((vecPos = token.find(",")) != std::string::npos)
			{
				vecToken = v.substr(0, vecPos);
				if (position.x == NULL)
				{
					position.x = std::stof(vecToken);
				}
				else if (position.y == NULL)
				{
					position.y = std::stof(vecToken);
				}
				else
				{
					position.z = std::stof(vecToken);
				}
			}
			// Set the transform->Position of this character to the new loaded position
			characters.at(characterID)->Transform->SetPosition(position);
		}

		// Update the Health of the Character
		if (k == "Health")
		{
			characters.at(characterID)->CharacterStats->SetCurrentHealth(std::stoi(v));
		}

		// Update the Mana of the Character
		if (k == "Mana")
		{
			characters.at(characterID)->CharacterStats->SetCurrentMana(std::stoi(v));
		}
		
	}
	std::cout << "     <--Final Result" << std::endl << std::endl;

	// With the new array, store the first section of the substring into a temp string up to the ":" so "CurrentHealth"

	// Compare the tempstring so that we know what datatype we need to parse the value to.

	// if tempstring = "CurrentHealth", we need to parse to int

	// Remove the text from the delimiter up to and including the :, so "CurrentHealth:", from the string

	// We are left with just the value "100" so lets parse it to int
}
