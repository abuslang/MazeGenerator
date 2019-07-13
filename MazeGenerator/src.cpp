/*
	create a grid of n x m cells, and initialize all of them to be unconnected.
	prompt the user for a maze generation algorithm from a list. just implement 1 for now.
	prompt the user for a path finding routine that finds the path from entrance to exit.
	pass the window into the chosen Maze Generating Routine, and have it update each frame.
	after its finsished, prompt user to select entrance and exit for the maze.
	then pass the window or grid in to the chosen pathfinding routine and have it update each frame.
	finally, crash and burn the computer.
*/

#include "SFML/Graphics.hpp"
//#include "Grid.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "Maze Generator!");


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			};
		}

		window.clear();
		//window.draw();
		window.display();
	}

	return 0;
}