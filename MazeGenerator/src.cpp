/*
	Contributors: Saad Bhatti, Abdusammad Quadri
	
	Description: 
	This program demonstrates various Maze generation and solution algorithms with
	the use of the SFML library for visuals.

	info about managing screens: https://github.com/SFML/SFML/wiki/Tutorial:-Manage-different-Screens

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
	RecursiveBacktracker backtracker;
	DFS dfs;
	Kruskals kruskals;
	MainMenu menu;

	Screens[MENU_SCREEN] = &menu;
	Screens[RECURSIVE_BACKTRACKER_SCREEN] = &backtracker;
	Screens[DFS_SCREEN] = &dfs;
	Screens[KRUSKALS_SCREEN] = &kruskals;



	int m = 20;				//get these from user
	int n = 20;

	int screenSize = (window.getSize().x < window.getSize().y) ? window.getSize().x : window.getSize().y;
	int gridSize = (m > n) ? m: n;

	Grid *maze;
	maze = new Grid(m, n, screenSize/gridSize); //instantiate a 20 x 20 grid with Cell sizes of 50 x 50
	

<<<<<<< HEAD
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




=======
>>>>>>> upstream/master
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