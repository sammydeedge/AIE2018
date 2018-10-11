#pragma once
#include "Fighter.h"
#include <string>


class Barbarian : public Fighter
{
public:
	Barbarian() : Fighter("Dragmurr the Bold")
	{
		setHealth(100);
		setAttackRange(15, 30);
		setDefenceRange(8, 17);
	}
	
 	
	int makeAttack1(int d20, int attackRoll) override;
	int makeAttack2(int d20, int attackRoll) override;
	int makeAttack3(int d20, int attackRoll) override;
	std::string getAttackName(int attackNumber);
	std::string getAttackDesc(int attackNumber);

protected:
	std::string attack1Name = "Wild Axe Chop";
	std::string attack1Desc = "risky: may be critical hit, may do damage to self";
	std::string attack2Name = "Sword Slash";
	std::string attack2Desc = "No chance of failure, but low chance of crit";
	std::string attack3Name = "Feast";
	std::string attack3Desc = "healing, some chance of failure";
};