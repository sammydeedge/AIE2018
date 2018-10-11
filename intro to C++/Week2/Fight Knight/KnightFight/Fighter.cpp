#include"Fighter.h"
#include "Arena.h"
#include<iostream>

Fighter::Fighter()
{
	m_name = "Bruce!";
}
Fighter::Fighter(const std::string& name)
{
	m_name = name;
}
void Fighter::setHealth(int HP) {
	m_health = HP;
}
int Fighter::getHealth() {
	return m_health;
}
void Fighter::setName(const std::string& name)
{
	m_name = name;
}
std::string  Fighter::getName() {
	return m_name;
}
void Fighter::setAttackRange(int min, int max) {
	m_attackMin = min;
	m_attackMax = max;
}
void Fighter::setDefenceRange(int min, int max) {
	m_defenceMin = min;
	m_defenceMax = max;
}

int Fighter::getAttackMin() {
	return m_attackMin;
}
int Fighter::getAttackMax() {
	return m_attackMax;
}
int Fighter::getDefenceMin() {
	return m_defenceMin;
}
int Fighter::getDefenceMax() {
	return m_defenceMax;
}
void Fighter::setHelper(int helper) {
	m_diehelper = helper;

	if (helper >=4)
	{
		int ATKmax = getAttackMax();
		int ATKmin = getAttackMin();
		int DEFmax = getDefenceMax();
		int DEFmin = getDefenceMin();
		m_diehelper = 0;
		++ATKmax;
		++ATKmin;
		++DEFmax;
		++DEFmin;
		setAttackRange(ATKmin, ATKmax);
		setDefenceRange(DEFmin, DEFmax);

	}

}
int Fighter::getHelper() {
	return m_diehelper;
}
 
int Fighter::defendAgainst(int  DMG, int currentDEF) {
	int health = getHealth();
	std::string title = getName();
	if (DMG == 0)
	{
		return 0;
	}
	else if (DMG < currentDEF)
	{
		std::cout << title << "'s defence is absolute!" << std::endl;
		return currentDEF - DMG;
	}
	else
	{
		std::cout << title << " defends, preventing " << currentDEF << " points of damage" << std::endl;
		health -= (DMG - currentDEF);
		setHealth(health);
		std::cout << title << " is now at " << health << " health." << std::endl;
	}
	
}


