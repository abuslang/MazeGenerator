

#ifndef GRID_H
#define GRID_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "Cell.h"

class Grid : public sf::Drawable
{

private:
	int numRows;	//num of rows
	int numCols;	//num of cols
	int s;	//size of cell
	std::vector<Cell> cellArray;

public:
	Grid(int m, int n, int s);	//create a m x n grid with empty cells of size s x s
	~Grid();					//deletes the cell array

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;	//will draw the current state of the grid.

	//accessor methods
	int getState(int row, int col);
	int getState(int idx);
	int getNumRows();
	int getNumCols();

	//mutator methods
	void setState(int row, int col, int state);
	void setState(int idx, int state);
	void setColor(int idx, sf::Color color);
	
};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

Grid::Grid(int m, int n, int s) : cellArray(m*n), numRows(m), numCols(n)
{
	//create a m x n grid with empty cells of size s x s

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
	//FIXME: free the vector
}//end destructor

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//draw the state of the Grid/cellArray
	for(auto cell : cellArray)
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




#endif // !GRID_H
