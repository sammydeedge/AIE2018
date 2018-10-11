#include "Board.h"
#include <iostream>



//Sets up a 3x3 board with all squares set to be "empty".
Board::Board() 
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			field[y][x] = Empty;
		}
	}
}


//Checks if the win condition (3 Noughts, or Crosses in a line) has been met.
bool Board::winCheck()
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			//Win by 3 symbols in a column.
			if (field[0][x] == symbol &&
				field[1][x] == symbol &&
				field[2][x] == symbol)
			{
				system("cls");
				printPlayfield();
				std::cout << getSymbolString() << " wins!" << std::endl;
				return true;
			}
			//Win by 3 symbols in a row.
			else if (field[y][0] == symbol &&
					field[y][1] == symbol &&
					field[y][2] == symbol)
			{
				system("cls");
				printPlayfield();
				std::cout << getSymbolString() << " wins!" << std::endl;
				return true;
			}
		}
	}
		//Win by 3 symbols in a diagonal.
	if (field[1][1] == symbol && 
		( (field[0][0] == symbol &&		
		field[2][2] == symbol) ||
		(field[0][2] == symbol) &&
		 (field[2][0] == symbol)))
		{
		 
		 system("cls");
		 printPlayfield(); 
		 std::cout << getSymbolString() << " wins!" << std::endl;
		 return true;
		}
	 else {
		 return false;
	 }
}

//Checks if the board is full of noughts & crosses, thus the game ending in a tie.
bool Board::boardFull() 
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			if (field[y][x] == Empty)
			{
				return false;
			}
			
		}
	}
	std::cout << "The Board is full, there is no winner." << std::endl;
	return true;
}

//Changes the symbol at location (row, col) to the current player's symbol.
//The function returns a boolean, it will return false if an incorrect input is made.
bool Board::setSpace(int row, int col)
{
	//Checking to make sure the numbers are valid (ie in the range 1-3).
	if (row > 3 || row < 0 || col > 3 || col < 0)
	{
		std::cout << "Invalid entry!" << std::endl;
		system("pause");
		system("cls");
		return false;
	}
	//A symbol may only be added to an empty space.
	else if (field[col][row] == Empty)
	{
		field[col][row] = symbol;
		return true;
	}
	else 
	//If it isn't empty, an error message is displayed.
	{
		std::cout << "Sorry, that space is already taken! Please choose another!" << std::endl;
		system("pause");	
		system("cls");
		return false;
	}
}

//Returns the appropriate character(O, X or -) that corresponds to the squares state (Nought, Cross or Empty).
char Board::getSpace(int row, int col) {
	int symbol = field[col][row];
	if (symbol == Empty)
	{
		return '-';
	}
	else if (symbol == Nought)
	{
		return 'O';
	}
	else if (symbol == Cross)
	{
		return 'X';
	}
	else
	{
		return ' ';
	}
	
}
//Prints out the current 3x3 playfield.
void Board::printPlayfield()
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			std::cout << getSpace(y, x);
		}
		std::cout << std::endl;
	}
}
//Outputs the instructions and takes in player input.
bool Board::playTurn()
{
	system("cls");
	printPlayfield();
	int col = 0;
	int row = 0;

	//Instruction to player.
	std::cout << "Player " << playerTurn << "'s turn (" << getSymbolString() << ")" << std::endl;
	std::cout << "Select column by entering a number (1 for left, 2 for middle, 3 for right)" << std::endl;
	std::cin >> col;
	//If the input fails (e.g. player enters letters), an error message pops up,
	//The invalid entry is cleared out of the system, then the game returns "false".
	//This false response, leads to the game looping around, giving the player a chance to reenter their input.
	if (std::cin.fail())
	{
		std::cout << "Invalid column entry!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		system("pause");
		return false;
	}
	else
	{		//The same input fail check as done for the col input above.
		std::cout << "Select row by entering a number (1 for top, 2 for middle, 3 for bottom)" << std::endl;
		std::cin >> row;
		if (std::cin.fail())
		{
			std::cout << "Invalid row entry!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			system("pause");
			return false;
		}
		else
		{
	//If no input fail occurs, it is sent to setSpace, it still may fail, as per the function.
			return setSpace(row - 1, col - 1);

		}

	}

}

//Takes the symbol value, returns a string (for use in instructions, player winning, etc.)
std::string Board::getSymbolString() {
	if (symbol == 1)
	{
		return "Nought";
	}
	else if (symbol == 2)
	{
		return "Cross";
	}
	else
	{
		return 0;
	}
}
//After a turn is correctly taken, this function changes the appropriate variables to run the next turn.
void Board::nextTurn ()
{
	if (playerTurn == 1)
	{
		playerTurn = 2;
		symbol = Cross;
	}
	else if (playerTurn == 2)
	{
		playerTurn = 1;
		symbol = Nought;
	}
}