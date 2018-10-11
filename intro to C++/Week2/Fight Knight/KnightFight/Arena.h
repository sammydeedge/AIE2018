#pragma once
#include "Fighter.h"

class Arena {
public:
	
		struct charProfile
	{
			enum charOptions
			{
				emptySelect,
				Barbarian,
				Paladin,
				Pyromancer
			};

			charOptions choice;
		std::string name;
		std::string type;
		int health;
	};

		charProfile charRoster [4] =
		{
			{charProfile::emptySelect, "Empty", "Empty",0},
			{charProfile::Barbarian, "Dragmurr the Bold", "Barbarian", 100},
			{charProfile::Paladin, "Vincente the Pure", "Paladin", 100},
			{charProfile::Pyromancer, "Smoldris the Scorching", "Pyromancer",100}
		};

	
	int characterListSize = 3;
	Arena();
	void setPlayerCharacter(int playerNo, charProfile character);
	std::string characterNameforPlayer(int PlayerNo);
	std::string fighterTypeofPlayer(const int PlayerNo);
	Arena::charProfile::charOptions getEnumforPlayer(const int PlayerNo);
	void setPlayerTurn(int playerNo);
	int getPlayerTurn();
	int getOpponentTurn();
	void changeTurn();
	int getHealth(int PlayerNo);

	int rolld20();
	int randomRange(int min, int max);

private:
	int playerTurn;
	charProfile combatants[2];

};