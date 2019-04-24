#include "pav_pch.h"
#include "GameState.h"


pav::GameState::GameState()
{
	ConnectToDB();
}


pav::GameState::~GameState()
{
}

void pav::GameState::ConnectToDB()
{
	dbcon = new DataBaseConnection("remotemysql.com", "xLrH61KxG0", "Ps26I2WARu", "xLrH61KxG0", 3306, true);
}

void pav::GameState::UpdateGameState(int characterID, std::string s)
{
	// Break the string into substrings and place inside of an array
	//std::istringstream iss(s);
	//std::vector<std::string> results ((std::istream_iterator<std::string>(iss)))

	// Create a query
	string query1 = "SELECT * FROM players WHERE(id ='" + std::to_string(characterID) + "');";
	string resultString;
	// Call the query
	MYSQL_RES* res = dbcon.fetchInformation(query1);
	int unsigned columns = mysql_num_fields(res);
	MYSQL_ROW row;

	if (row = mysql_fetch_row(res))
	{
		cout << "Query Success!";
	}
	// Confirm Success of Query
	else
		cout << "Invalid Query";

	// Store everything in a string
	for (size_t i = 0; i < columns; i++)
	{
		resultString += (row[i]);
		resultString += "|";
	}

	// In theory, we now have the row which will be broken up into substrings past this point.

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

	while ((pos = resultString.find(splitDelimiter)) != std::string::npos)
	{
		token = resultString.substr(0, pos);

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
		// Update the Rotation of character
		if (k == "Rotation")
		{
			glm::vec3 euler;
			size_t vecPos;
			std::string vecToken;

			// The string probably needs to look like "n,n,n," not "n,n,n" but not 100% sure
			while ((vecPos = token.find(",")) != std::string::npos)
			{
				vecToken = v.substr(0, vecPos);
				if (euler.x == NULL)
				{
					euler.x = std::stof(vecToken);
				}
				else if (euler.y == NULL)
				{
					euler.y = std::stof(vecToken);
				}
				else
				{
					euler.z = std::stof(vecToken);
				}
			}
			// Set the transform->Position of this character to the new loaded position
			characters.at(characterID)->Transform->SetRotation(euler);
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
		// Update the State of the Character
		if (k == "Moving")
		{
			// The player is not moving
			if (v == "0")
			{

			}
			// The player is moving
			if (v == "1")
			{
				// TODO: Update Animation here
			}
		}
		if (k == "Casting")
		{
			// The player is not casting
			if (v == "0")
			{

			}
			// The player is casting
			if (v == "1")
			{
				// TODO: Update Animation here
			}
		}
		if (k == "Attacking")
		{
			// The player is not Attacking
			if (v == "0")
			{

			}
			// The player is Attacking
			if (v == "1")
			{
				// TODO: Update Animation here
			}
		}
		if (k == "Alive")
		{
			// The player is not casting
			if (v == "0")
			{

			}
			// The player is casting
			if (v == "1")
			{
				// TODO: Update Animation here
			}
		}
	}
	std::cout << "     <--Final Result" << std::endl << std::endl;

	// With the new array, store the first section of the substring into a temp string up to the ":" so "CurrentHealth"

	// Compare the tempstring so that we know what datatype we need to parse the value to.

	// if tempstring = "CurrentHealth", we need to parse to int

	// Remove the text from the delimiter up to and including the :, so "CurrentHealth:", from the string

	// We are left with just the value "100" so lets parse it to int
}

void pav::GameState::UpdateGameInformation(std::string s)
{
	// Delcaire the Delimiter
	std::string splitDelimiter = "|";
	std::string valueDelimiter = ":";

	size_t pos = 0;
	std::string token;

	// Create vectors for storing the keys and values
	std::vector<std::string> stateKey;
	std::vector<std::string> stateValue;

	while ((pos = s.find(splitDelimiter)) != std::string::npos)
	{
		// Make the First substring (Key:Value)
		token = s.substr(0, pos);

		size_t subPos = 0;
		std::string subToken;
		while ((subPos = token.find(valueDelimiter)) != std::string::npos)
		{
			// Break the substrings even furthur (Key) and (Value)
			subToken = token.substr(subPos + valueDelimiter.length());
			token = token.substr(0, subPos);
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
		
		// Make sure we have a reference to the Score here, Or maybe we actually store the score here.

		// Update the Score of the Game
		if (k == "DwarfResources")
		{
			// TODO: Update the score of the dwarfs with v
		}

		if (k == "OrcResources")
		{
			// TODO: Update the score of the orcs with v
		}

		// Determine if the game is still running
		if (k == "GameOver")
		{
			// Game is still in progress
			if (v == "0")
			{
				// Probably do nothing here, so we can probably get rid of this if statement
			}

			// Game is over
			if (v == "1")
			{
				// Handle Gameover logic
			}
		}
	}
}
