#include"Paladin.h"
#include"Fighter.h"
#include<iostream>



//Sword Slash Attack
int Paladin::makeAttack1(int d20, int attackRoll)
{
	int damage;
	int helper = getHelper();
	int randomResult = d20 + helper;

	if (randomResult >= 20) {
		damage = attackRoll + 7;
		std::cout << "A critical hit!" << Paladin::getName() << " deals " << damage << " damage." << std::endl;
		setHelper(0);
	}
	else {
		damage = attackRoll;
		std::cout << Paladin::getName() << " deals " << damage << " damage." << std::endl;
	}
	return damage;
}
//Equipment Upgrade 
int Paladin::makeAttack2(int d20, int attackRoll)
{
	int boost;
	int helper = getHelper();
	int selfHealth = getHealth();
	int ATKmin = getAttackMin();
	int ATKmax = getAttackMax();
	int DEFmin = getDefenceMin();
	int DEFmax = getDefenceMax();

	 if (d20 + helper >= 10) {
		 boost = (d20 - 9) / 2.5f;
		 std::cout << Paladin::getName() << "upgrades his armour and weapons! Attack, Defence & Health boosted by " << boost << " points!" << std::endl;
		 ATKmin += boost;
		 ATKmax += boost;
		 setAttackRange(ATKmin, ATKmax);
		 DEFmin += boost;
		 DEFmax += boost;
		 setDefenceRange(DEFmin, DEFmax);
		 selfHealth += boost;
		 setHealth(selfHealth);
		 setHelper(0);
		 return 0;
	}
	else {
	std::cout << Paladin::getName() << " can't find his silver polish! The upgrade has failed!" << std::endl;
	int helper = getHelper();
	setHelper(helper++);
	return 0;
	}
}
//Prayer
int Paladin::makeAttack3(int d20, int attackRoll)
{
	int boost;
	int helper = getHelper();
	int randomResult = d20 + helper;
	getHealth();
	if (randomResult >= 5) {
		boost = (randomResult - 4) * 3;
		std::cout << Paladin::getName() << "'s prayers are answered! They heal " << boost << " damage." << std::endl;
		int newHealth = getHealth() + boost;
		setHealth(newHealth);
		setHelper(0);
		return 0;
	}
	else {
		std::cout << Paladin::getName() << "'s prayers fall on deaf ears. See this is why you need to have something cute and fluffy nearby for a blood sacrifice. No healing occurs" << std::endl;
		int helper = getHelper();
		setHelper(helper++);
		return 0;
	}
}
std::string Paladin::getAttackName(int attackNumber)
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
}

std::string Paladin::getAttackDesc(int attackNumber)
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
}