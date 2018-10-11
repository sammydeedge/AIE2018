#pragma once
#include <string>

class Board {
public:
	enum spaceStatus {
		Empty,
		Nought,
		Cross
	};

	

	Board();
	void printPlayfield();
	bool setSpace(int row, int col);
	char getSpace(int row, int col);
	bool winCheck();
	bool boardFull();
	bool playTurn();
	std::string getSymbolString();
	void nextTurn();
	

private:
	spaceStatus field[3][3]{ { Empty , Empty , Empty }, { Empty , Empty , Empty }, { Empty , Empty , Empty } };
int playerTurn = 1;
	spaceStatus symbol = Board::Nought;
};