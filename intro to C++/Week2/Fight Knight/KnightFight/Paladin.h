#pragma once
#include"Fighter.h"

class Paladin : public Fighter
{
public:
	Paladin() : Fighter("Vincente the Pure")
	{
		setHealth(100);
		setAttackRange(11, 24);
		setDefenceRange(5, 13);
	}

	int makeAttack1(int d20, int attackroll) override;
	int makeAttack2(int d20, int attackroll) override;
	int makeAttack3(int d20, int attackroll) override;
	std::string getAttackName(int attackNumber);
	std::string getAttackDesc(int attackNumber); 

private:
	std::string attack1Name = "Sword Slash";
	std::string attack1Desc = "No chance of failure, but low chance of crit";
	std::string attack2Name = "Equipment Upgrade";
	std::string attack2Desc = "Can raise ATK and DEF stats, chance of failure";
	std::string attack3Name = "Prayer";
	std::string attack3Desc = "healing, some chance of failure";
};