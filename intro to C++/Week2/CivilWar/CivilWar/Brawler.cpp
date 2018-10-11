#include "Hero.h"
#include "Brawler.h"
#include <iostream>

//Captain America & Bucky Barnes can defend each other.
// If the attacked hero has a lower health than their partner, and the ability succeeds (determined by simulated d20 roll), the partner defends.
// Partner takes the damage, which is halved.
void Brawler::partnerAssist(int damage, Hero defender, Hero partner) {
	int defHealth = defender.getHealth();
	int partHealth = partner.getHealth();
	if ((rolld20() > 17) && defHealth < partHealth)
	{
		std::cout << partner.getName() << " defended " << defender.getName() "!" << std::endl;
		std::cout << partner.getName() << " took " << damage / 2 << " points of damage." << std::endl;
		partner.setHealth
	}
}

