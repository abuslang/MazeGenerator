#ifndef TEST_GRID_H
#define TEST_GRID_H
#pragma once

#include "cScreen.h"
#include "Grid.h"

class TestGrid : public cScreen
{
private:
public:
	TestGrid();

	int Run(sf::RenderWindow &window, Grid &grid);
};

//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

TestGrid::TestGrid()
{

}

int TestGrid::Run(sf::RenderWindow &window, Grid &grid)
{
	bool Running = true;

	while (Running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return -1;
		}

		window.clear();
		window.draw(grid);
		window.display();
	}

	//never reaches here
	return -1;
}

#endif
