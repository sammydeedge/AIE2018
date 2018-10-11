#pragma once
#include "Fighter.h"

class Mage : public Fighter
{
public:
	Mage();
	Mage(const std::string& name);
	int getEnergy();
	void setEnergy(int energy);
	

protected:
	int energyLevel;

};