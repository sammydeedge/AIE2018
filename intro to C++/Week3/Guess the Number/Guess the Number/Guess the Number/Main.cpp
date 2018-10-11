#include "Game.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>

Game game;

struct HighScore
{
	char name[256];
	int score;
};

HighScore scores[] =
{
	{ "James", 10 },
	{ "Lucas", 15 },
	{ "Arthur", 8 },
	{ "Kim", 13 },
	{ "Zuse", 20 },
};

bool operator> (const HighScore& first, const HighScore& second)
{
	return first.score > second.score;
}

int run = 0;



template<typename T>
void bubbleSort(T array[], int size)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < size - 1; ++i)
		{
			T& first = array[i];
			T& second = array[i + 1];
			if (first > second)
			{
				T temp = first;
				first = second;
				second = temp;
				sorted = false;
			}
		}
	}

	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i].name << " -- " << array[i].score << std::endl;
	}

	
}

template<typename T>
int bottomOfBoard(T array[], int size)
{
	int lastplace = array[size-1].score;
	return lastplace;
}

void guessNumber_menu()
{
	char key = 0;
	std::cout << "Welcome to Guess-A-Number, the game where you do all the hard calculations!" << std::endl;
	std::cout << "Press S to start the game, or press A to see the Computer play!" << std::endl;
	std::cin >> key;
	if (key == 's' || key == 'S')
	{
		game.setCurrentScreen(Game::gameplay);
	}
	else if (key == 'a'|| key == 'A')
	{
		game.setCurrentScreen(Game::AIgameplay);
	}
	else
	{
		system("cls");
	}

}

void guessNumber_gameplay()
{
	game.guessNo = 0;
	bool gameOver = false;
	game.setAnswer(game.randomNumber());
	while (!gameOver)
	{
		bool GuessMade;
		int guess;
		do 
		{	
			GuessMade = true;
			guess = 0;
			
			std::cout << "Guess a number between 1 and 1000:";
			std::cin >> guess;
			if (std::cin.fail())
			{
				std::cout << "Invalid entry!" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				system("pause");
				system("cls");
				GuessMade = false;
			}
		} while (!GuessMade);
			system("cls");
		gameOver = game.response(guess);
	}
	system("pause");
	game.setCurrentScreen(Game::gameOver);
}

void guessNumber_AIgameplay()
{
	game.guessNo = 0;
	bool gameOver = false;
	game.setAnswer(game.randomNumber());
	game.m_aiMax = 1;
	game.m_aiMax = 1000;
	while (!gameOver)
	{
		int guess = (game.m_aiMin + game.m_aiMax) / 2;

		gameOver = game.AIresponse(guess);

	}
	system("pause");
	game.setCurrentScreen(Game::AIgameOver);
}

void guessNumber_AIgameOver(int NoOfGuesses)
{
	system("cls");
	std::cout << "The computer got the answer in " << NoOfGuesses << " guesses. Think you can do better?" << std::endl;
	std::cout << "---------------------" << std::endl << "PRESS Q TO QUIT|||PRESS R TO RESTART";
	char key = 0;

	std::cin >> key;
	if (key == 'r')
	{
		system("cls");
		game.setCurrentScreen(Game::menu);

	}
	if (key == 'q')
	{
		game.setCurrentScreen(Game::quit);
	}


}

void guessNumber_gameOver(int NoOfGuesses)
{
	std::fstream fin("HiScore.dat", std::ios_base::in | std::ios_base::binary);

	if (fin.good())
	{
		fin.read((char*)scores, sizeof(HighScore) * 5);	
		fin.close();
	}

	bubbleSort(scores, 5);

	if (NoOfGuesses < bottomOfBoard(scores, 5))
	{
		std::string playerName;
		std::cout << "Congratulations! Enter your name below to put it on the scoreboard!" << std::endl;
		std::cin >> playerName;
		if (playerName.size() > 255)
		{
			playerName.resize(255);
		}
		strcpy(scores[4].name, playerName.data());
		scores[4].score = NoOfGuesses;
		system("cls");

	}
	
	bubbleSort(scores, 5);

	std::fstream fout("HiScore.dat", std::ios_base::out | std::ios_base::binary);
	if (fout.good())
	{
		fout.seekp(0, std::ios::beg);
		fout.write((char*)scores, sizeof(HighScore) * 5);
		fout.close();
	}
	std::cout << "---------------------" << std::endl << "PRESS Q TO QUIT|||PRESS R TO RESTART";
	char key = 0;

	std::cin >> key;
	if (key == 'r')
	{
		system("cls");
		game.setCurrentScreen(Game::menu);
		
	}
	if (key == 'q')
	{
		game.setCurrentScreen(Game::quit);
	}

	
}

int main()
{
	while (game.m_currentState != Game::quit)
	{
		switch (game.m_currentState)
		{
		case Game::menu:
		{
			guessNumber_menu();
			break;
		}
		case Game::gameplay:
		{
			guessNumber_gameplay();
			break;
		}
		case Game::AIgameplay:
		{
			guessNumber_AIgameplay();
			break;
		}
		case Game::gameOver:
		{
			guessNumber_gameOver(game.guessNo);
			break;
		}
		case Game::AIgameOver:
		{
			guessNumber_AIgameOver(game.guessNo);
			break;
		}
		}
	} 
	return 0;
}
