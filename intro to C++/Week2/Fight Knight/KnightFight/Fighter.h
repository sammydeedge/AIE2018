#pragma once
#include <string>

class Fighter
{
protected:
	std::string m_name;
	int m_health;
	int m_attackMin;
	int m_attackMax;
	int m_defenceMin;
	int m_defenceMax;
	int m_diehelper;
	std::string attack1Name;
	std::string attack1Desc;
	std::string attack2Name;
	std::string attack2Desc;
	std::string attack3Name;
	std::string attack3Desc;

public:
		Fighter();
		Fighter(const std::string& name);

		void setHealth(int HP);
		int getHealth();

		std::string getName();
		void setName(const std::string& name);

		void setAttackRange(int min, int max);
		int getAttackMin();
		int getAttackMax();


		void setDefenceRange(int min, int max);
		int getDefenceMin();
		int getDefenceMax();

		void setHelper(int helper);
		int getHelper();
		

		virtual int makeAttack1(int d20, int attackRoll) = 0;
		virtual int makeAttack2(int d20, int attackRoll) = 0;
		virtual int makeAttack3(int d20, int attackRoll) = 0;


		int defendAgainst(int DMG, int currentDEF);


};