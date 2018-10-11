#include"Fighter.h"
#include"Barbarian.h"
#include "Arena.h"
#include<iostream>

//Wild Axe Attack
int Barbarian::makeAttack1(int d20, int attackRoll)
{
	int helper = getHelper();
	int randomResult = d20 + helper;
	int selfHealth = getHealth();
	int damage;

	if (randomResult <= 5)
	{
		std::cout << "The Axe sales wide! " << Barbarian::getName() << " takes " << randomResult * 2 << " damage!" << std::endl;

		selfHealth -= randomResult * 2;
		setHealth(selfHealth);
		setHelper(++helper);
		return 0;
	}
	else if (randomResult >= 15) {
		damage = attackRoll + (5 * (randomResult - 14));
		std::cout << "A critical hit!" << Barbarian::getName() << " deals " << damage << " damage." << std::endl;
		return damage;
	}
	else {
		damage = attackRoll;
		std::cout << Barbarian::getName() << " deals " << damage << " damage." << std::endl;
		setHelper(0);
			return damage;
	}
}
//Sword Slash Attack
int Barbarian::makeAttack2(int d20, int attackRoll)
{
	int helper = getHelper();
	int randomResult = d20 + helper;
	int damage;

	if (randomResult <= 20) {
		damage = (randomResult - 19) + attackRoll + 7;
		std::cout << "A critical hit!" << Barbarian::getName() << " deals " << damage << " damage." << std::endl;
		setHelper(0);
		return damage;
	}
	else {
		damage = attackRoll;
		std::cout << Barbarian::getName() << " deals " << damage << " damage." << std::endl;
			return damage;
	}
}
//Feast (Healing) Ability
int Barbarian::makeAttack3(int d20, int attackRoll)
{
	int helper = getHelper();
	int randomResult = d20 + helper;
	getHealth();
	if (randomResult >= 5) {
		int boost = (randomResult - 4) * 2;
		std::cout << "A brief banquet is held by " << Barbarian::getName() << ". They heal " << boost << " damage." << std::endl;
		int newHealth = getHealth() + boost;
		setHealth(newHealth);
		setHelper(0);
		return 0;
	}
	else {
		std::cout << Barbarian::getName() << " fumbles his silverware, the feast has fallen into dissarray! No healing occurs!" << std::endl;
		int helper = getHelper();
		setHelper(helper++);
		return 0;
	}
}
std::string Barbarian::getAttackName(int attackNumber)
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
std::string Barbarian::getAttackDesc(int attackNumber)
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


