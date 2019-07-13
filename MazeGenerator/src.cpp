/*
	Brainstorming:
	info about managing screens: https://github.com/SFML/SFML/wiki/Tutorial:-Manage-different-Screens

	create a grid of n x m cells, and initialize all of them to be unconnected.
	prompt the user for a maze generation routine from a list. just implement 1 for now.
	prompt the user for a path finding routine that finds the path from entrance to exit.

	each of these "routines" can be implemented as a screen, check the link above

	pass the window into the chosen Maze Generating Routine, and have it update each frame.
	after its finsished, prompt user to select entrance and exit for the maze.
	then pass the window or grid in to the chosen pathfinding routine and have it update each frame.
	finally, crash and burn the computer.
*/

#include "SFML/Graphics.hpp"
#include "Screens.h"
#include "Grid.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Maze Generator!");	//this window will be passed around from screen to screen
	std::vector<cScreen*> Screens;											//vector of available screens, can switch from screen to screen by returning its index			
	
	int screen = 0;			//initital screen will be test screen, in an actual application, should be menu screen
	Test testScreen;
	Screens.push_back(&testScreen);
	int m =20;	//get these from user
	int n = 20;
	Grid maze(m, n, 50);	//instantiate a 20 x 20 grid with Cell sizes of 50 x 50

	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}
	window.close();
	return 0;
}