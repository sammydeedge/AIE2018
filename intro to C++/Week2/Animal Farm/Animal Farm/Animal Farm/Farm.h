#pragma once
#include "Animal.h"

const int MAX_ANIMALS = 100;

class Farm 
{
public:
	Farm();
	~Farm();

	void listAnimals();

	void addAnimal(animal* animal);

	void soundOff();

	void operator+=(class Animal* animal);

private:
	animal* m_animals[MAX_ANIMALS];
	int m_currentNumberOfAnimals = 0;

};