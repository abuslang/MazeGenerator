

#ifndef GRID_H
#define GRID_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "Cell.h"

class Grid : public sf::Drawable
{

private:
	std::vector<Cell> cellArray;

public:
	Grid(int m, int n, int s);	//create a m x n grid with empty cells of size s x s
	~Grid();					//deletes the cell array

	//Will draw the current state of the grid.
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later


Grid::Grid(int m, int n, int s) : cellArray(m*n)
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
	//free the vector
}//end destructor

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//draw the state of the Grid/cellArray
	for(auto cell : cellArray)
	{
		target.draw(cell);
	}

}//end draw


#endif // !GRID_H
