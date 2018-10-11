#include "Board.h"
#include <iostream>




int main() 
{
	//booleans used to control gameplay loop
	bool gameOver;
	bool playAgain;
	
	do {
		Board field;
		gameOver = false;
		playAgain = false;
		while (!gameOver)
		{
			//checks to make sure turn has run successfully (no invalid entry eg letters, no enter symbols into
			//already filled spaces. If it fails, it skips post turn functions, and loops back to the playTurn function
			bool didTurn = field.playTurn();
			//if the turn succeeds, check if game is over (either bc there is a winner or all squares are filled)
			//then move to next turn
			if (didTurn)
			{
				gameOver = (field.winCheck() || field.boardFull());
				field.nextTurn();
				system("pause");
			}

		}
		//post game text
		system("cls");
		field.printPlayfield();
		std::cout << "GAME OVER" << std::endl << "---------------------" << std::endl << "PRESS Q TO QUIT|||PRESS R TO RESTART";
		char key = 0;
		
		std::cin >> key;
		if (key == 'r')
		{
			playAgain = true;
		}
		if (key == 'q')
		{
			playAgain = false;
		}
	
	} while (playAgain);
}
