#pragma once
#include <string>
#include <random>
#include <ctime>

class Hero {
private:
	std::string m_name;
	int m_health;
	int m_attackMin;
	int m_attackMax;
	std::string m_attackName;
	bool isAlive;
	int m_defenceMin;
	int m_defenceMax;
	//speed
	//roll
public:
	Hero();
	Hero(const std::string& name, const std::string& attackName);

	std::string getName() const;
	void setName(const std::string& name);

	int randomRange(int min, int max);
	int rolld20();
	
	void setHealth(int HP);
	int getHealth();

	void setAttackRange(int min, int max);
	int makeAttack();

	void setDefenceRange(int min, int max);
	int getDefence();

	void setAttackName(const std::string& attackName);
	std::string getAttackName() const;

	void setLiving(int HP);
	bool getLiving();

};

