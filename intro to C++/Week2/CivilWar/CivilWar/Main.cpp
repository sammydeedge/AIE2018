#include <iostream>
#include <string>
#include "Hero.h"
#include "Brawler.h"

bool gameOver = false;

void attack() {

}


int main() {
	//Character setup Update if adding states/speeds etc.
	Hero  hawk, falc, ant, witch, iron, war, widow, panther, vision, spider;
	Brawler::Hero cap, buck;
	cap.setName("Captain");
	cap.setAttackName("Shield Throw!");
	buck.setName("Bucky Barnes");
	buck.setAttackName("Communist Punch!");


	hawk.setName("Hawkeye");
	hawk.setAttackRange(7, 14);
	hawk.setAttackName("Several Arrows!");
	falc.setName("Falcon");
	falc.setAttackRange(11, 16);
	falc.setAttackName("Magpie Divebomb!");
	
	ant.setName("Ant-man");
	ant.setAttackRange(13, 17);
	ant.setAttackName("Quantum Butt Kick!");
	witch.setName("Scarlet Witch");
	witch.setAttackRange(13, 17);
	witch.setAttackName("Telekinetic Slap!");


	iron.setName("Iron Man");
	iron.setAttackRange(19, 25);
	iron.setAttackName("Goddamn Missiles?!");
	war.setName("War Machine");
	war.setAttackRange(14, 22);
	war.setAttackName("Freaking Gatling Guns?!");
	widow.setName("Black Widow");
	widow.setAttackRange(9, 14);
	widow.setAttackName("8-armed Karate Chop!");
	panther.setName("Black Panther");
	panther.setAttackRange(15, 20);
	panther.setAttackName("Kitty Scratch uwu!");
	vision.setName("Vision");
	vision.setAttackRange(10, 17);
	vision.setAttackName("Laser Eye Surgery");
	spider.setName("Spiderman");
	spider.setAttackRange(7, 16);
	spider.setAttackName("whatever a spider uses!");

	Hero teamCap[6] = { cap, hawk, falc, buck, ant, witch };
	Hero teamIron[6] = { iron, war, widow, panther, vision, spider };

	while (!gameOver) {
		char key = 0;
		std::cout << "Press S to begin simulation";
		std::cin >> key;
		if (key == 's')
		{
			for (int i = 0; i < 13; i++) {
				system("cls");

				std::cout << "Press A to simulate " << teamCap[i].getName() << "'s attack" << std::endl;
				std::cin >> key;
				if (key == 'a') {
					std::cout << teamCap[i].getName() << " used " << teamCap[i].getAttackName() << std::endl;
					system("pause");
				}
			}
		}
		system("pause");
	}
}
