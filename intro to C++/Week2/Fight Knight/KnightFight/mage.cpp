#include "Mage.h"

Mage::Mage()
{
	m_name = "Merlin!";
}

Mage::Mage(const std::string& name)
{
	m_name = name;
}

int Mage::getEnergy()
{
	return energyLevel;
}

void Mage::setEnergy(int energy)
{
	energyLevel = energy;
}
