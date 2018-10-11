#include"Arena.h"

Arena::Arena()
{
	for (int i = 0; i < 2; ++i)
	{
		combatants[i] = charRoster[0];
	}
	setPlayerTurn(1);
}

void Arena::setPlayerCharacter(const int playerNo, charProfile character)
{
	combatants[playerNo-1] = character;
}


Arena::charProfile::charOptions Arena::getEnumforPlayer(const int PlayerNo)
{
	return combatants[PlayerNo-1].choice;
}

std::string Arena::characterNameforPlayer(const int PlayerNo)
{
	return combatants[PlayerNo-1].name;
}

std::string Arena::fighterTypeofPlayer(const int PlayerNo)
{
	return combatants[PlayerNo-1].type;
}

void Arena::setPlayerTurn(int playerNo)
{
	playerTurn = playerNo;
}

int Arena::getPlayerTurn()
{
	return playerTurn;
}

int Arena::getOpponentTurn()
{
	int current = playerTurn;
	if (current == 1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

void Arena::changeTurn()
{
	if (playerTurn == 1)
	{
		playerTurn = 2;
	}
	else if (playerTurn == 2)
	{
		playerTurn = 1;
	}
}

int Arena::getHealth(int PlayerNo)
{
	return combatants[PlayerNo - 1].health;
}

int Arena::rolld20() {
	int randomValue = ((rand() % 20) + 1);
	return randomValue;
}

int Arena::randomRange(int min, int max)
{
	int range = max - min;
	int randomValue = (rand() % (range + 1)) + min;
	return randomValue;
}

//int Arena::makeAttack()
//{
//
//}
