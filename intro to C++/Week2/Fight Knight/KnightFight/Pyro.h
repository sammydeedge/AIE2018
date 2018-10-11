#pragma once
#include "Fighter.h"
#include "Mage.h"


class Pyromancer : public Mage
{
public:
	Pyromancer() : Mage("Smoldris the Scorching")
	{
		setHealth(100);
		setAttackRange(6, 14);
		setDefenceRange(2, 10);
		setEnergy(5);
	}


	int makeAttack1(int d20, int attackRoll) override;
	int makeAttack2(int d20, int attackRoll) override;
	int makeAttack3(int d20, int attackRoll) override;

	std::string getAttackName(int attackNumber);
	std::string getAttackDesc(int attackNumber);

protected:
	std::string attack1Name = "Throw Fire";
	std::string attack1Desc = "Standard Fire cast, may fail";
	std::string attack2Name = "Unleash the Heat";
	std::string attack2Desc = "Attacks with stored energy, may inflict burn on enemies";
	std::string attack3Name = "Feed the Fire";
	std::string attack3Desc = "Increase energy level, may also heal";
};