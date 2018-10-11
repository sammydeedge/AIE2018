#pragma once
#include "Hero.h"

//Class that applies to Captain America & Bucky Barnes

class Brawler : public Hero {
public :
	Brawler() : Hero()
	{
		setAttackRange(15, 30);
		setDefenceRange(5, 10);
	}
	void partnerAssist(int damage, Hero defender, Hero partner);

};