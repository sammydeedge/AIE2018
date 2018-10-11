#include "Pokemon.h"
#include <iostream>
#include<string>

//void pokemon::setPokedex(std::string description) {
//	p_pokedex = description;
//}
//
//void pokemon::approach()
//{
//	std::cout << "As you approach " << animal::getName() << " your pokedex chimes" << std::endl;
//	std::cout << p_pokedex;
//}

void squirtle::speak() {
	std::cout << "Squir-Squirtle" << std::endl;
}

std::string squirtle::getSpecies()
{
	return "Squirtle";
}

void charmander::speak() {
	std::cout << "Char-Char" << std::endl;
}

std::string charmander::getSpecies()
{
	return "Charmander";
}
void bulbasaur::speak() {
	std::cout << "Bulba-Bul" << std::endl;
}

std::string bulbasaur::getSpecies()
{
	return "Bulbasaur";
}
