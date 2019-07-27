
#pragma once

#include "BasicScreen.h"
#include "Grid.h"

class TestGrid : public BasicScreen
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
	window.setTitle("Test Grid Screen");
	bool Running = true;
	sf::Event event;

	while (Running)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return (-1);
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					return (-1);
			}
		}

		window.clear();
		window.draw(grid);
		window.display();
	}

	//never reaches here
	return (-1);
}
