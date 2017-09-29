#include <iostream>
#include "board.cpp"

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
	std::cout << myBoard.getDimension() << std::endl;
}


