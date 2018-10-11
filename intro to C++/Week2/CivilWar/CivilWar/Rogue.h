#pragma once
#include "Hero.h"

class Rogue : public Hero {
	Rogue() : Hero()
	{
		setAttackRange(10, 20);
		setDefenceRange(5, 10);
		//speeeed
	}
	void sneakAttack();
};