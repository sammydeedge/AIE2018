#include <iostream>
#include <random>
#include <ctime>
/*
void attackConditions()
{
	bool isHealthy = true;
	int currentAmmo = 10;

	bool shouldAttack = (isHealthy && currentAmmo > 1) || (currentAmmo > 5) ;

	char c = 0;
	std::cout << "Enter a character!\n";
	std::cin >> c;

	if (shouldAttack)
	{
		std::cout << "We should attack!\n";
	}
	else
	{
		std::cout << "We should not attack!\n";
	}
}


void calculator() {

	float numberOne = 0.0f;
	float numberTwo = 0.0f;
	char operation = 0;

std::cout << "Enter the first number: ";
std::cin >> numberOne;

std::cout << "Enter the second number: ";
std::cin >> numberTwo;

std::cout << "Which operation would you like to do? Press + for addition, - for subtraction, * for multiplication or / for division";
std::cin >> operation;

	switch (operation)
	{
	case '+':
		{
			std::cout << "The answer is: " << numberOne + numberTwo << "\n";
				break;
		}
	case '-':
		{
			std::cout << "The answer is: " << numberOne - numberTwo << "\n";
				break;
		}
	case '*':
		{
			std::cout << "The answer is: " << numberOne * numberTwo << "\n";
				break;
		}
	case '/':
		{
			std::cout << "The answer is: " << numberOne / numberTwo << "\n";
				break;
		}
		default:
		{
			std::cout << "Uhhhh... That isn't... an operation\n";
				break;
		}
	}
	
}

void KnightFight() {

char choice = 0;
//Knight One: Francis
float KN1Health = 100.0f;
float KN1Damage = 20.0f;

//Knight Two: Peter
float KN2Health = 100.0f;
float KN2Damage = 15.0;

int doAttack(int currentHealth, int amountOfDamage, int multiplier)
{
	float totalDamage = amountOfDamage * multiplier;

	float finalHealth = currentHealth - totalDamage;
	if (finalHealth < 0)
	{
		finalHealth = 0;
	}

	return finalHealth;
}

int healthCheck() {

	if (KN1Health <= 0) {
		std::cout << "Sir Francis (P1) has fallen in combat. Sir Peter (P2) is victorious!";
			//Game end sequence
	}
	else if (KN2Health <= 0) {
		std::cout << "Sir Peter (P2) has been slain. Sir Peter (P1) is victorious!";
			//Game end sequence
	}
	else if (KN1Health <= 50) {
		std::cout << "Sir Francis (P1) is wounded badly. He has " << KN2Health << " health remaining.";
	}
	else if (KN2Health <= 0) {
		std::cout << "Sir Peter (P2) is struggling with his injuries. He has " << KN2Health << " health remaing.";
			//Game end sequence
	}
	else {
		std::cout << "Sir Francis (P1) has " << KN1Health << " health remaing.";
		std::cout << "Sir Peter (P2) has " << KN2Health << " health remaing.";
	}
	return 0;
}

int randomNumberRange(int min, int max)
{
	if (min == max)
	{
		return min;
	}
	else if (min > max)
	{
		int minholder = min;
		min = max;
		max = minholder;
	}
	
	int range = max - min;

	float randomValue = (rand() % (range + 1)) + min;
	srand((unsigned int)time(nullptr));


}
int main()
{
	srand((unsigned int)time(nullptr));

	float RegMulti = 0.8f + (randomNumberRange(0, 5) / 20);
	float RiskMulti = (randomNumberRange(2, 7) / 5);

	/* attackConditions();
	calculator();*/


/*

	//Attack

	std::cout << "Player 1, press q for regular attack or w for risky attack.\n Player 2, press o for regular attack or p for risky attack";
	std::cin >> choice;

	switch (choice)
	{
	case 'q': {
		if (KN1Health < 50) { KN2Health -= doAttack(KN2Health, KN1Damage, RegMulti); }
		else {
			KN2Health -= doAttack(KN2Health, KN1Damage, (RegMulti / 2));
			std::cout << "Sir Peter (P2) has " << KN2Health << " health points remaining\n";
			break;
		}
	}
	case 'w': {
		if (KN1Health < 50) { KN2Health -= doAttack(KN2Health, KN1Damage, RiskMulti); }
		else {
			KN2Health -= doAttack(KN2Health, KN1Damage, (RiskMulti / 2));
			std::cout << "Sir Peter (P2) has " << KN2Health << " health points remaining\n";
			break;
		}

	}
	case 'o': {
		if (KN2Health < 50) { KN1Health -= doAttack(KN1Health, KN2Damage, RegMulti); }
		else {
			KN1Health -= doAttack(KN1Health, KN2Damage, (RegMulti / 2));
			KN1Health -= doAttack(KN1Health, KN2Damage, RegMulti);
			std::cout << "Sir Francis (P1) has " << KN1Health << " health points remaining\n";
			break;
		}
	}
	case 'p': {
		if (KN2Health < 50) { KN1Health -= doAttack(KN1Health, KN2Damage, RiskMulti); }
		else {
			KN1Health -= doAttack(KN1Health, KN2Damage, (RiskMulti / 2));
			std::cout << "Sir Francis (P1) has " << KN1Health << " health points remaining\n";
			break;
		}
	}


	}
	while ((KN1Health > 0) || (KN2Health > 0))
		system("pause");
	}

}
*/

void doSomething()
{
	doSomething();
}


int main()
{
	srand((unsigned int)time(nullptr));

	system("pause");
	return 0;
}