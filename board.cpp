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
	bool isSolved(std::vector<std::vector<int> > solvedBoard)
	{
		for(int i = 0; i < DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION; j++)
			{
				if(currentBoard[i] != solvedBoard[i])
				{
					return false;
				}
			}
		}
		return true;
	}
	void printBoard()
	{
		for(int i = 0; i < DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION; j++)
			{
				std::cout << currentBoard[i][j];
			}
			std::cout << std::endl;
		}
	}
				
private:
	const int DIMENSION = 3;
	std::vector<std::vector<int> > currentBoard;
};

