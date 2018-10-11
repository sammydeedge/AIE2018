#include"Fighter.h"
#include"Barbarian.h"
#include"Paladin.h"
#include"Arena.h"
#include "Mage.h"
#include "Pyro.h"
#include<iostream>

bool gameOver = false;
Barbarian barbarian;
Paladin paladin;
Pyromancer pyromancer;
//Generic non-entity character that controls aspects of the fight
Arena gameControls;

Barbarian* BARB = &barbarian;
Paladin* PALD = &paladin;
Pyromancer* PYRO = &pyromancer;

void endCheck() {
	int P1Health = gameControls.getHealth(1);
	int P2Health = gameControls.getHealth(1);
	if (P1Health <= 0)
	{
		std::cout << gameControls.characterNameforPlayer(1) << " has been slain. " << gameControls.characterNameforPlayer(2) << " is victorious!";
		gameOver = true;

	}
	else if (P2Health <= 0)
	{
		std::cout << gameControls.characterNameforPlayer(2) << " has been slain. " << gameControls.characterNameforPlayer(1) << " is victorious!";
		gameOver = true;
	}
}

void characterSelect()
{
	int player = 1;
	bool selectionComplete = false;
	while(!selectionComplete)
	{ 
		system("cls");
		int selectNo = 0;
		std::cout << "Player " << player << ", choose your warrior!" << std::endl;
		for (int i = 1; i <= gameControls.characterListSize; ++i)
		{
			std::cout << i << ". " << gameControls.charRoster[i].name << " (" << gameControls.charRoster[i].type << ")" << std::endl;
		}
		std::cin >> selectNo;
		Arena::charProfile PlayChar = gameControls.charRoster[selectNo];
	
		gameControls.setPlayerCharacter(player, PlayChar);
		++player;
		if (player >= 3)
		{
			selectionComplete = true;
		}
	}
}

int main() {
	//booleans to control gameplay loop
	bool playAgain;
	bool gameOver;

	do {

			playAgain = false;
			gameOver = false;
			characterSelect();

			

			system("cls");
			std::cout << "Two combatants enter the arena.\nThe first is " << gameControls.characterNameforPlayer(1) << ", a " << gameControls.fighterTypeofPlayer(1) << "." << std::endl;
			std::cout << "The Second is " << gameControls.characterNameforPlayer(2) << ", a " << gameControls.fighterTypeofPlayer(2) << "." << std::endl;
			char key = 0;
			std::cout << "Press C to continue" << std::endl;
			std::cin >> key;
			if (key == 'c') {
				while (!gameOver)
				{
					key = 0;

					system("cls");

					Arena::charProfile::charOptions whosUp = gameControls.getEnumforPlayer(gameControls.getPlayerTurn());
					Arena::charProfile::charOptions whosDefending = gameControls.getEnumforPlayer(gameControls.getOpponentTurn());

					if (whosUp == Arena::charProfile::charOptions::Barbarian)//make umpire a seperate class
					{
						int die = gameControls.rolld20();
						int ATKmin = BARB->getAttackMin();
						int ATKmax = BARB->getAttackMax();

						std::cout << BARB->getName() << " steps up" << std::endl;
						std::cout << "Press 1 to use " << BARB->getAttackName(1) << " (" << BARB->getAttackDesc(1) << ")" << std::endl;
						std::cout << "Press 2 to use " << BARB->getAttackName(2) << " (" << BARB->getAttackDesc(2) << ")" << std::endl;
						std::cout << "Press 3 to use " << BARB->getAttackName(3) << " (" << BARB->getAttackDesc(3) << ")" << std::endl;
						std::cin >> key;

						system("cls");
						if (key == '1')
						{
							int ATKmin = BARB->getDefenceMin();
							int ATKmax = BARB->getDefenceMax();
							int damage = BARB->makeAttack1(die, gameControls.randomRange(ATKmin, ATKmax));
							if (whosDefending == Arena::charProfile::charOptions::Paladin)
							{
								int DEFmin = PALD->getDefenceMin();
								int DEFmax = PALD->getDefenceMax();
								PALD->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}
							else if (whosDefending == Arena::charProfile::charOptions::Pyromancer)
							{
								int DEFmin = PYRO->getAttackMin();
								int DEFmax = PYRO->getAttackMax();
								PYRO->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}

						}
						else if (key == '2')
						{
							int damage = BARB->makeAttack2(die, gameControls.randomRange(ATKmin, ATKmax));
							if (whosDefending == Arena::charProfile::charOptions::Paladin)
							{
								int DEFmin = PALD->getDefenceMin();
								int DEFmax = PALD->getDefenceMax();
								PALD->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}
							else if (whosDefending == Arena::charProfile::charOptions::Pyromancer)
							{
								int DEFmin = PYRO->getAttackMin();
								int DEFmax = PYRO->getAttackMax();
								PYRO->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}
						}
						else if (key == '3')
						{
							BARB->makeAttack3(die, gameControls.randomRange(ATKmin, ATKmax));
						}
						system("pause");
					}

					if (whosUp == Arena::charProfile::charOptions::Paladin)
					{
						int min = PALD->getAttackMin();
						int max = PALD->getAttackMax();
						int die = gameControls.rolld20();

						std::cout << PALD->getName() << " steps up" << std::endl;
						std::cout << "Press 1 to use " << PALD->getAttackName(1) << " (" << PALD->getAttackDesc(1) << ")" << std::endl;
						std::cout << "Press 2 to use " << PALD->getAttackName(2) << " (" << PALD->getAttackDesc(2) << ")" << std::endl;
						std::cout << "Press 3 to use " << PALD->getAttackName(3) << " (" << PALD->getAttackDesc(3) << ")" << std::endl;
						std::cin >> key;

						system("cls");
						if (key == '1')
						{
							int damage = PALD->makeAttack1(die, gameControls.randomRange(min, max));
							if (whosDefending == Arena::charProfile::charOptions::Barbarian)
							{
								int DEFmin = BARB->getAttackMin();
								int DEFmax = BARB->getAttackMax();
								BARB->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}
							else if (whosDefending == Arena::charProfile::charOptions::Pyromancer)
							{
								int DEFmin = PYRO->getAttackMin();
								int DEFmax = PYRO->getAttackMax();
								PYRO->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}

						}
						else if (key == '2')
						{
							PALD->makeAttack2(die, gameControls.randomRange(min, max));
						}
						else if (key == '3')
						{
							PALD->makeAttack3(die, gameControls.randomRange(min, max));
						}
						system("pause");
					}

					if (whosUp == Arena::charProfile::charOptions::Pyromancer)
					{
						int min = PYRO->getAttackMin();
						int max = PYRO->getAttackMax();
						int die = gameControls.rolld20();

						std::cout << PYRO->getName() << " steps up" << std::endl;
						std::cout << "Press 1 to use " << PYRO->getAttackName(1) << " (" << PYRO->getAttackDesc(1) << ")" << std::endl;
						std::cout << "Press 2 to use " << PYRO->getAttackName(2) << " (" << PYRO->getAttackDesc(2) << ")" << std::endl;
						std::cout << "Press 3 to use " << PYRO->getAttackName(3) << " (" << PYRO->getAttackDesc(3) << ")" << std::endl;
						std::cin >> key;

						system("cls");
						if (key == '1')
						{
							int damage = PYRO->makeAttack1(die, gameControls.randomRange(min, max));
							if (whosDefending == Arena::charProfile::charOptions::Barbarian)
							{
								int DEFmin = BARB->getAttackMin();
								int DEFmax = BARB->getAttackMax();
								BARB->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));

							}
							else if (whosDefending == Arena::charProfile::charOptions::Paladin)
							{
								int DEFmin = PALD->getDefenceMin();
								int DEFmax = PALD->getDefenceMax();
								PALD->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}

						}
						else if (key == '2')
						{
							int damage = PYRO->makeAttack2(die, gameControls.randomRange(min, max));
							if (whosDefending == Arena::charProfile::charOptions::Barbarian)
							{
								int DEFmin = BARB->getAttackMin();
								int DEFmax = BARB->getAttackMax();
								BARB->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}
							else if (whosDefending == Arena::charProfile::charOptions::Paladin)
							{
								int DEFmin = PALD->getDefenceMin();
								int DEFmax = PALD->getDefenceMax();
								PALD->defendAgainst(damage, gameControls.randomRange(DEFmin, DEFmax));
							}

						}
						else if (key == '3')
						{
							PYRO->makeAttack3(die, gameControls.randomRange(min, max));
						}
						system("pause");
					}

					endCheck();
					gameControls.changeTurn();
				}
				

			}
		
		system("cls");
		std::cout << "GAME OVER" << std::endl << "---------------------" << std::endl << "PRESS Q TO QUIT|||PRESS R TO RESTART";
		key = 0;
		std::cin >> key;
		if (key == 'r')
		{
			playAgain = true;
		}
		if (key == 'q')
		{
			playAgain = false;
		}

	} while (playAgain);
}
