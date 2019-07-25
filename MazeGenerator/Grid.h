

#ifndef GRID_H
#define GRID_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "Cell.h"

class Grid : public sf::Drawable
{

private:
	int numRows;			//num of rows
	int numCols;			//num of cols
	int s;					//size of cell
	bool hasBeenGenerated;	//FIXME:may not use, flag for whether the maze has already been generated or not
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
	void setColor(int row, int col, sf::Color color);
	void setColor(int idx, sf::Color color);
	void resetGeneration();
	void resetSolution();
	
};

#endif // !GRID_H
