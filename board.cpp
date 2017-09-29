#include <iostream>
#include <vector>
class MyBoard
{
public:
	MyBoard()
	{
	}
	~MyBoard()
	{
	}
	int getDimension()
	{
		return DIMENSION;
	}
	std::vector<std::vector<int> > getCurrentBoard()
	{
		return currentBoard;
	}
	bool setBoardPosition(int row, int column, int value)
	{
		if(DIMENSION > row && DIMENSION > column)
		{
			std::cout << row << std::endl;
			this->currentBoard[row][value] = 0;
			std::cout << row << std::endl;
			std::cout << column << std::endl;
			this->currentBoard[row][column] = value;
			return true;
		}
		return false;
	}
private:
	const int DIMENSION = 3;
	std::vector<std::vector<int> > currentBoard;

};

