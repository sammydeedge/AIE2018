#include "Pyro.h"
#include<iostream>

//Throw Fire (Standard Fire cast, may fail)
int Pyromancer::makeAttack1(int d20, int attackRoll)
{
	int damage;
	
	if (attackRoll < 6)
	{
		std::cout << Pyromancer::getName() << " can't seem to get a spark going! The Fire Throw has failed!" << std::endl;
		int energy = getEnergy();
		setEnergy(energy + 2);
		return 0;
	}
	else
	{
		damage = (d20/4) + (attackRoll / 5);
		std::cout << Pyromancer::getName() << " deals " << damage << " damage.";
		return damage;

	}
}

//Unleash the Heat (Attacks with stored energy, may inflict burn on enemies)
int Pyromancer::makeAttack2(int d20, int attackRoll)
{
	int energy = getEnergy();

	float percentUsed = (attackRoll / 40.0f) + 0.5f;
	int energyUse = percentUsed * energy;
	//if energyUse is over 15, inflict burn
	return energyUse * 2;
	setEnergy(energy - energyUse);

}

//Feed the Fire (Increase energy level, may also heal)
int Pyromancer::makeAttack3(int d20, int attackRoll)
{
	int energy = getEnergy();
	int health = getHealth();

	setEnergy(energy + attackRoll / 3);

		if (attackRoll > 15)
		{
			health += (attackRoll - 15) * 2;
			setHealth(health);
		}
	return 0;
}

std::string Pyromancer::getAttackName(int attackNumber)
{
	if (attackNumber == 1)
	{
		return attack1Name;
	}
	else if (attackNumber == 2)
	{
		return attack2Name;
	}
	else if (attackNumber == 3)
	{
		return attack3Name;
	}
	else
	{
		return "Error Invalid Attack Name (Barbarian)";
	}
}
std::string Pyromancer::getAttackDesc(int attackNumber)
{
	if (attackNumber == 1)
	{
		return attack1Desc;
	}
	else if (attackNumber == 2)
	{
		return attack2Desc;
	}
	else if (attackNumber == 3)
	{
		return attack3Desc;
	}
	else
	{
		return "Error Invalid Attack Description (Barbarian)";
	}
}
