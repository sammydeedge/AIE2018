#include "Hero.h"
#include <iostream>

Hero::Hero()
{
	setHealth(100);
	setLiving(100);
}
Hero::Hero(const std::string& title)
{
	m_name = title;
}
std::string Hero::getName() const
{
	return m_name;
}
void Hero::setName(const std::string& name)
{
	m_name = name;
}

void Hero::setHealth(int HP) {
	m_health = HP;
}

int Hero::getHealth()
{
	return m_health;
}

int Hero::randomRange(int min, int max)
{
	srand((unsigned int)time(nullptr));
	int range = max - min;
	int randomValue = (rand() % (range + 1)) + min;
	return randomValue;
}
int Hero::rolld20() {
	return randomRange(1, 20);
}

void Hero::setAttackRange(int min, int max)
{
	m_attackMin = min;
	m_attackMax = max;
}
int Hero::makeAttack() 
{
	int attack = randomRange(m_attackMin, m_attackMax);
	return attack;
}
std::string Hero::getAttackName() const
{
	return m_attackName;
}
void Hero::setAttackName(const std::string& attackName)
{
	m_attackName = attackName;
}
void Hero::setLiving(int HP)
{
	m_health = HP;
	if (m_health <= 0)
	{
		isAlive = false;
	}
}
bool Hero::getLiving(){
	return isAlive;
}
void Hero::setDefenceRange(int min, int max)
{
	m_defenceMin = min;
	m_defenceMax = max;
}
int Hero::getDefence()
{
	int defence = randomRange(m_defenceMin, m_defenceMax);
	return defence;
}