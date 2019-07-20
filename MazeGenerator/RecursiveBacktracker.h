#ifndef RECURSIVE_BACKTRACKER_H
#define RECURSIVE_BACKTRACKER_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"
#include <stack>

class RecursiveBacktracker : public BasicScreen
{

private:
public:
	RecursiveBacktracker();
	~RecursiveBacktracker();
	int Run(sf::RenderWindow &window, Grid &grid);
};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

RecursiveBacktracker::RecursiveBacktracker()
{
}

RecursiveBacktracker::~RecursiveBacktracker()
{
}

int RecursiveBacktracker::Run(sf::RenderWindow &window, Grid &grid)
{
	bool Running = true;
	int visitedCount = 0;
	std::stack<std::pair<int, int>> stack;	//holds a stack of indices of the cells

	//start from top-left cell
	int row = 0;
	int col = 0;
	stack.push(std::make_pair(row, col));
	grid.setState(row, col, CELL_VISITED);
	visitedCount = 1;


	auto offset = [&](int row, int col)
	{
		return (stack.top().first + row) * grid.getNumCols() + (stack.top().second + col);
	};

	//render loop
	while (Running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return -1;
		}

		window.clear();

		//the algo is in this if
		//it's inside an if b/c we want to se the maze generate in realtime
		if (visitedCount < (grid.getNumCols() * grid.getNumRows()))
		{
			// Create a set of unvisted neighbours
			std::vector<int> neighbours;

			//now check for neighbors in N, S, E and W directions

			//if the cell is anywhere BUT row 0, then the cell has NORTH neighbor
			if(stack.top().first > 0 && ((grid.getState(offset(-1, 0)) & CELL_VISITED) == 0x0))
				neighbours.push_back(0);
			//if the cell is anywhere but the last column, then the cell has EAST neighbor
			if (stack.top().second < (grid.getNumCols() - 1) && ((grid.getState(offset(0, 1)) & CELL_VISITED) == 0x0))
				neighbours.push_back(1);
			//if the cell is anywhere but the bottom row, then it has SOUTH neighbor
			if (stack.top().first < (grid.getNumRows() - 1) && ((grid.getState(offset(1, 0)) & CELL_VISITED) == 0x0))
				neighbours.push_back(2);
			//if the cell is anywhere but the 1st column, then it has WEST neighbor
			if (stack.top().second > 0 && ((grid.getState(offset(0, -1)) & CELL_VISITED) == 0x0))
				neighbours.push_back(3);



			//now the neighbor vector may not be populated with unvisited neighbors
			if (!neighbours.empty())
			{
				// Choose one available neighbour at random
				int nextCellDir = neighbours[rand() % neighbours.size()];

				switch (nextCellDir)
				{
				case 0:	//NORTH
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | CELL_PATH_N);
					grid.setState(offset(-1, 0), grid.getState(offset(-1, 0)) | CELL_PATH_S);
					stack.push(std::make_pair((stack.top().first - 1), (stack.top().second + 0)));
					break;

				case 1:	//EAST
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | CELL_PATH_E);
					grid.setState(offset(0, 1), grid.getState(offset(0, 1)) | CELL_PATH_W);
					stack.push(std::make_pair((stack.top().first + 0), (stack.top().second + 1)));
					break;

				case 2:	//SOUTH
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | CELL_PATH_S);
					grid.setState(offset(1, 0), grid.getState(offset(1, 0)) | CELL_PATH_N);
					stack.push(std::make_pair((stack.top().first + 1), (stack.top().second + 0)));
					break;

				case 3:	//WEST
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | CELL_PATH_W);
					grid.setState(offset(0, -1), grid.getState(offset(0, -1)) | CELL_PATH_E);
					stack.push(std::make_pair((stack.top().first + 0), (stack.top().second - 1)));
					break;
				}//end switch

				//make neighbor cell visited
				grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | CELL_VISITED);
				visitedCount++;
			}
			else 
			{
				stack.pop();
			}
		}//end algo if

		window.draw(grid);
		window.display();
	}

	//never reaches here
	return -1;

}

#endif