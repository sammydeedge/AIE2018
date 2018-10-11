#include "Animal.h"
#include "Pokemon.h"
#include "Farm.h"
#include <iostream>

bool gameOver;
char key = 0;

void loserGameOver() {
	system("cls");
	std::cout << "You bring in no cute furry animals, and get very lonely. When your body is found days after" << std::endl;
	std::cout << "your death, the people that come to collect your body note with wry amusement the fact that" << std::endl;
	std::cout << "you died playing poker with a stick figure drawn on a piece of paper" << std::endl;
	std::cout << "Try playing along next time. GAME OVER!" << std::endl;
	std::cout << "PS Stickman Jim cleaned you out in poker" << std::endl;
	std::cout << "Press Q to quit or R to restart" << std::endl;
	std::cin >> key;
	if (key == 'q')
	{
		gameOver = true;
	}
	else if (key == 'r')
	{
		gameOver = false;
	}
	else {
		key = 0;
		std::cout << "Press Q to quit or R to restart" << std::endl;
	}
}
void main() {
	Farm animalFarm;
	while (!gameOver) {
		char key = 0;
		system("cls");
		std::cout << "After many years of work and saving up your income from your job, you can finally do your dream job" << std::endl;
		std::cout << "You have retired to the country and set up your business: the fantasy animal sanctuary!" << std::endl;
		std::cout << "The sanctuary is currently empty, would you like to bring someone in? Y/N" << std::endl;
		std::cin >> key;
		if (key == 'n')
		{
			loserGameOver();
			}
		if (key == 'y') {
			bool farmStart = true;
			while (farmStart){
			key = 0;
			
			std::cout << "Press s to bring in squirtle, c to bring in charmander, b to bring in bulbasaur, l for a list of animals, t to hear them all";
			std::cin >> key;
			switch (key) {
				case 's' :
				{
					animalFarm.addAnimal(new squirtle());
					system("pause");
					system("cls");
					break;
				}
				case 'c':
				{
					animalFarm.addAnimal(new charmander());
					system("pause");
					system("cls");
					break;
				}
				case 'b':
				{
					animalFarm.addAnimal(new bulbasaur());
					system("pause");
					system("cls");
					break;
				}
				case 'l':
				{
					animalFarm.listAnimals();
					system("pause");
					system("cls");
					break;
				}
				case 't':
				{
					animalFarm.soundOff();
					system("pause");
					system("cls");
					break;
				}
			}
			}
			

		}
	}
}