#include "Game.h"
#include <iostream>
#include <random>
#include <ctime>

Game::Game()
{
	m_currentState = Game::menu;
}

int Game::randomNumber()
{
	srand((unsigned int)time(nullptr));
	return ((rand() % 1000) + 1);
	
}

void Game::setAnswer(int number)
{
	m_answer = number;
}

int Game::getAnswer()
{
	return m_answer;
}

void Game::setCurrentScreen(gameScreen state)
{
	m_currentState = state;
}

bool Game::response(int guess)
{
	++guessNo;
	std::cout << "Guess #" << guessNo << ":" << std::endl;
		
	if (guess < m_answer)
	{
		std::cout << guess << "? That's too low!" << std::endl;
		return false;
	}
	else if (guess > m_answer)
	{
		std::cout << guess << "? That's too high!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "You got it! It was " << guess << std::endl;
		return true;
	}
}

bool Game::AIresponse(int guess)
{
	++guessNo;
	std::cout << "Guess #" << guessNo << ":" << std::endl;

	if (guess < m_answer)
	{
		std::cout << guess << "? That's too low!" << std::endl;
		m_aiMin = guess + 1;
		std::cout << "--------------------------------------------" << std::endl;
		return false;
	}
	else if (guess > m_answer)
	{
		std::cout << guess << "? That's too high!" << std::endl;
		m_aiMax = guess - 1;
		std::cout << "--------------------------------------------" << std::endl;
		return false;
	}
	else
	{
		std::cout << "You got it! It was " << guess << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		return true;
	}
	
}
