#ifndef DFS_H
#define DFS_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"

class DFS : public BasicScreen
{
private:
public:
	~DFS();
	int Run(sf::RenderWindow &window, Grid &grid);

};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

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



	bool paused = false;
	sf::Text pausedPrompt;
	pausedPrompt.setFont(font);
	pausedPrompt.setString("!PAUSED!");
	pausedPrompt.setCharacterSize(60);
	pausedPrompt.setOrigin(pausedPrompt.getLocalBounds().width / 2, pausedPrompt.getLocalBounds().height / 2);
	pausedPrompt.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	sf::Text finishedPrompt;
	finishedPrompt.setFont(font);
	finishedPrompt.setString("!Press Return To Continue!");
	finishedPrompt.setCharacterSize(39);
	finishedPrompt.setOrigin(finishedPrompt.getLocalBounds().width / 2, finishedPrompt.getLocalBounds().height / 2);
	finishedPrompt.setPosition(window.getSize().x / 2, window.getSize().y / 2);

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
				
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return && grid.getMazeSolFlag())
				{
					while (!stack.empty())
						stack.pop();
					return (MENU_SCREEN);
				}
				else if (event.key.code == sf::Keyboard::Space)
					paused = !paused;
					
			}
		}//while poll


		if (!paused)
		{
			if (stack.top() != end)
			{
				std::cout << "DFS is finding			\r";
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

					if (stack.top() == end)
						grid.setColor(offset(0, 0), sf::Color::Red);

				}
				else
				{
					//this is to reset the color to the default
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)));
					stack.pop();
				}
			}//end algo if
			else
			{
				std::cout << "DFS is done				\r";
				grid.setMazeSolFlag(true);
			}

		}//end if !paused
		
		window.clear();
		window.draw(grid);
		if (grid.getMazeSolFlag())
		{
			finishedPrompt.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			window.draw(finishedPrompt);

		}
		else if (paused)
		{
			pausedPrompt.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			window.draw(pausedPrompt);
		}
		window.display();
	}//end render loop

	//never reaches here
	return (-1);
}

#endif // !DFH_H
