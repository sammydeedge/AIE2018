#pragma once
#include <string>

class Game
{
public:
	enum gameScreen
	{
		menu,
		gameplay,
		AIgameplay,
		gameOver,
		AIgameOver,
		quit
	};

	gameScreen m_currentState;
	int guessNo;

	Game();

	int m_aiMin;
	int m_aiMax;


	int randomNumber();
	void setAnswer(int number);
	int getAnswer();

	void setCurrentScreen(gameScreen state);
	
	bool response(int guess);
	bool AIresponse(int guess);
	
protected:
	int m_answer;
	
	

};

template<typename T>
void readInput(const std::string& prefix, T& input)
{
	do
	{
		std::cout << prefix;	//Prefix asking user for input (e.g. "please input a number:")

		std::cin.clear();	//Clears any error messages
		std::cin.ignore(std::cin.rdbuf()->in_avail()); //Ignores the input made
		std::cin >> input;	//Asks the user for another input
	} while (std::cin.fail); //This function only loops when the input fails (e.g. inputting letters instead of numbers).
}