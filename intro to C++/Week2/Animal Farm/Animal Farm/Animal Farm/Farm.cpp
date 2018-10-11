#include "Farm.h"
#include <iostream>

Farm::Farm() {

}

Farm::~Farm() {
	for (int i = 0; i < m_currentNumberOfAnimals; ++i)
	{
		delete m_animals[i];
	}
}

void Farm::listAnimals()
{
	for (int i = 0; i < m_currentNumberOfAnimals; ++i)
	{
		std::cout << m_animals[i]->getSpecies() << std::endl;
	}
}

void Farm::addAnimal(animal* animal) {
	if (m_currentNumberOfAnimals >= MAX_ANIMALS) {
		std::cout << "Sorry! Your farm is full!";
		delete animal;
	}

	std::cout << animal->getSpecies() << " has been added to your farm" << std::endl;
	m_animals[m_currentNumberOfAnimals] = animal;
	m_currentNumberOfAnimals++;
}

void Farm::soundOff()
{
	for (int i = 0; i < m_currentNumberOfAnimals; ++i)
	{
		m_animals[i]->speak();
	}
}


void Farm::operator+=(Animal * animal);
{
	addAnimal(animal);
}