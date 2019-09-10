#include "Grid.h"
<<<<<<< HEAD
=======
#include <vector>
#include "Cell.h"

>>>>>>> upstream/master

Grid::Grid(int m, int n, int s) : cellArray(m*n), numRows(m), numCols(n)
{
	//create a m x n grid with empty cells of size s x s
<<<<<<< HEAD
	hasBeenGenerated = false;
=======
	mazeGenerated = false;
	mazeSolved = false;

>>>>>>> upstream/master
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cellArray[row*n + col] = Cell(row, col, s);
		}
	}
}//end constructor

Grid::~Grid()
{
	cellArray.clear();
	std::vector<Cell>().swap(cellArray);
}//end destructor

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//draw the state of the Grid/cellArray
	for (auto cell : cellArray)
	{
		target.draw(cell);
	}

}//end draw


//Accessor Methods
int Grid::getNumRows()
{
	return numRows;
}

int Grid::getNumCols()
{
	return numCols;
}

int Grid::getState(int row, int col)
{
	return cellArray[row*numCols + col].getState();
}

int Grid::getState(int idx)
{
	return cellArray[idx].getState();
}
<<<<<<< HEAD
=======
bool Grid::getMazeGenFlag()
{
	return mazeGenerated;
}
bool Grid::getMazeSolFlag()
{
	return mazeSolved;
}
>>>>>>> upstream/master

//Mutator Methods
void Grid::setState(int row, int col, int state)
{
	cellArray[row*numCols + col].setState(state);
}

void Grid::setState(int idx, int state)
{
	cellArray[idx].setState(state);
}

void Grid::setColor(int idx, sf::Color color)
{
	cellArray[idx].setColor(color);
}

void Grid::setColor(int row, int col, sf::Color color)
{
	cellArray[row*numCols + col].setColor(color);
}

<<<<<<< HEAD
void Grid::resetGeneration()
{
	hasBeenGenerated = false;
=======
void Grid::setMazeGenFlag(bool flag)
{
	mazeGenerated = flag;
}

void Grid::setMazeSolFlag(bool flag)
{
	mazeSolved = flag;
}

void Grid::resetGeneration()
{
	mazeGenerated = false;
	mazeSolved = false;

>>>>>>> upstream/master
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			cellArray[row*numCols + col].setState(0);
		}
	}
}

void Grid::resetSolution()
{
<<<<<<< HEAD
=======
	mazeSolved = false;
>>>>>>> upstream/master
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			cellArray[row*numCols + col].setState(cellArray[row*numCols + col].getState() & ~SOL_VISITED);
		}
	}
}