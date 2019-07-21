#ifndef DFS_H
#define DFS_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"

class DFS : public BasicScreen
{
private:
public:
	DFS();
	~DFS();
	int Run(sf::RenderWindow &window, Grid &grid);

};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

DFS::DFS(){}
DFS::~DFS(){}

int DFS::Run(sf::RenderWindow &window, Grid &grid)
{
	window.setTitle("Depth First Search Screen");
	srand(time(NULL));
	grid.resetSolution();

	bool Running = true;

	std::stack<std::pair<int, int>> stack;	//holds a stack of indices of the cells

	auto offset = [&](int row, int col)
	{
		return (stack.top().first + row) * grid.getNumCols() + (stack.top().second + col);
	};

	int row = rand() % (grid.getNumRows());
	int col = rand() % (grid.getNumCols());


	std::pair<int, int> start = std::make_pair(row, col);	
	stack.push(start);
	grid.setState(row, col, grid.getState(offset(0, 0)) | SOL_VISITED);
	grid.setColor(row, col, sf::Color::Green);

	row = rand() % (grid.getNumRows());
	col = rand() % (grid.getNumCols());

	std::pair<int, int> end = std::make_pair(row, col);
	grid.setColor(row, col, sf::Color::Red);

	while (Running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				while (!stack.empty())
					stack.pop();
				return (-1);
			}
				
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					while (!stack.empty())
						stack.pop();
					return (-1);
				}
					
			}
		}//while poll



		if (stack.top() != end)
		{
			//vector of unvisited neighbors
			std::vector<int> neighbours;

			//populate the vector with viable neighbors
			if ((grid.getState(offset(0, 0)) & PATH_N) == PATH_N && (grid.getState(offset(-1, 0)) & SOL_VISITED) == 0)
				neighbours.push_back(0);
			if ((grid.getState(offset(0, 0)) & PATH_E) == PATH_E && (grid.getState(offset(0, 1)) & SOL_VISITED) == 0)
				neighbours.push_back(1);
			if ((grid.getState(offset(0, 0)) & PATH_S) == PATH_S && (grid.getState(offset(1, 0)) & SOL_VISITED) == 0)
				neighbours.push_back(2);
			if ((grid.getState(offset(0, 0)) & PATH_W) == PATH_W && (grid.getState(offset(0, -1)) & SOL_VISITED) == 0)
				neighbours.push_back(3);

			if (!neighbours.empty())
			{
				int nextCellDir = neighbours[rand() % neighbours.size()];
				switch (nextCellDir)
				{

				case 0:	//NORTH
					stack.push(std::make_pair((stack.top().first - 1), (stack.top().second + 0)));
					break;

				case 1:	//EAST
					stack.push(std::make_pair((stack.top().first + 0), (stack.top().second + 1)));
					break;

				case 2:	//SOUTH
					stack.push(std::make_pair((stack.top().first + 1), (stack.top().second + 0)));
					break;

				case 3:	//WEST
					stack.push(std::make_pair((stack.top().first + 0), (stack.top().second - 1)));
					break;
				}//end switch

				grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | SOL_VISITED);
				grid.setColor(offset(0, 0), sf::Color::Magenta);

				if(stack.top() == end)	
					grid.setColor(offset(0, 0), sf::Color::Red);

			}
			else
			{
				//this is to reset the color to the default
				grid.setState(offset(0, 0), grid.getState(offset(0, 0)));
				stack.pop();
			}
		}//end algo if



		window.clear();
		window.draw(grid);
		window.display();
	}//end render loop

	//never reaches here
	return (-1);
}

#endif // !DFH_H
