#pragma once
#include <string>

class animal
{
public:
	animal();
	virtual ~animal() = default;
	virtual	std::string getSpecies() = 0;
	virtual std::string setName()
	virtual std::string getName() = 0;
	virtual void speak() = 0;


};