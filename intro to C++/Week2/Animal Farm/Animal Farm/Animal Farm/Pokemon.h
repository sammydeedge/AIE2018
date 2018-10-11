#pragma once
#include "Animal.h"

//class pokemon : public animal
//{
//public:
//	void speak() override;
//	void approach() override;
//	void setPokedex(std::string description);
//	virtual void getSound() = 0;
//protected:
//	std::string p_pokedex;
//};

class squirtle : public animal
{
public:
	std::string getSpecies() override;
	void speak() override;
};

class charmander : public animal
{
public:
	std::string getSpecies() override;
	void speak() override;
};
class bulbasaur : public animal
{
public:
	std::string getSpecies() override;
	void speak() override;
};