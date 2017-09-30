#include <iostream>
#include "board.h"

int main()
{
	MyBoard myBoard;
	myBoard.setBoardPosition(0,0,1);
	myBoard.setBoardPosition(0,1,3);
	myBoard.setBoardPosition(0,2,4);
	myBoard.setBoardPosition(1,0,8);
	myBoard.setBoardPosition(1,0,8);
	myBoard.setBoardPosition(1,1,6);
	myBoard.setBoardPosition(1,2,2);
	myBoard.setBoardPosition(2,0,7);
	myBoard.setBoardPosition(2,1,5);
	myBoard.setBoardPosition(2,2,0);
	MyBoard solvedBoard;
	solvedBoard.setBoardPosition(0,0,1);
	solvedBoard.setBoardPosition(0,1,2);
	solvedBoard.setBoardPosition(0,2,3);
	solvedBoard.setBoardPosition(1,0,8);
	solvedBoard.setBoardPosition(1,1,0);
	solvedBoard.setBoardPosition(1,2,4);
	solvedBoard.setBoardPosition(2,0,7);
	solvedBoard.setBoardPosition(2,1,6);
	solvedBoard.setBoardPosition(2,2,5);
	std::cout << myBoard.getDimension() << std::endl;
	myBoard.printBoard();
}


