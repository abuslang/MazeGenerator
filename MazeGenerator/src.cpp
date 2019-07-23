/*
	Contributors: Saad Bhatti, Abdusammad Quadri
	
	Description: 
	This program demonstrates various Maze generation and solution algorithms with
	the use of the SFML library for visuals.


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
#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Maze Generator!");	//this window will be passed around from screen to screen
	std::vector<BasicScreen*> Screens(100);	//vector of available screens, can switch from screen to screen by returning its index			
	
	//initializing the screens
	Test testScreen;
	TestGrid testGrid;
	RecursiveBacktracker backtracker;
	DFS dfs;
	Kruskals kruskals;
	Menu menu((float)window.getSize().x, (float)window.getSize().y);

	Screens[MENU_SCREEN] = &menu;
	Screens[TEST_GRID_SCREEN] = &testGrid;
	Screens[RECURSIVE_BACKTRACKER_SCREEN] = &backtracker;
	Screens[DFS_SCREEN] = &dfs;
	Screens[KRUSKALS_SCREEN] = &kruskals;



	int m = 10;				//get these from user
	int n = 10;

	int screenSize = (window.getSize().x < window.getSize().y) ? window.getSize().x : window.getSize().y;
	int gridSize = (m > n) ? m: n;

	Grid *maze;
	maze = new Grid(m, n, screenSize/gridSize); //instantiate a 20 x 20 grid with Cell sizes of 50 x 50

	

	//FIXME: FOR TEST ONLY
	//backtracker.Run(window, *maze);
	//dfs.Run(window, *maze);
	/*
	kruskals.Run(window, *maze);
	kruskals.Run(window, *maze);
	kruskals.Run(window, *maze);
	dfs.Run(window, *maze);
	window.close();
	*/




	int screen = MENU_SCREEN;
	while (screen >= 0)
	{
		std::cout << screen << std::endl;
		screen = Screens[screen]->Run(window, *maze);
	}
	window.close();
	



	delete maze;
	return (0);
}