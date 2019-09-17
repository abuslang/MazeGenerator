/*
	Authors: Saad Bhatti, Abdusammad Quadri
	
	Description: 
	This program demonstrates various Maze generation and solution algorithms. The algorithms are displayed
	using the SFML library.
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


	int m = 12;				
	int n = 12;

	int screenSize = (window.getSize().x < window.getSize().y) ? window.getSize().x : window.getSize().y;
	int gridSize = (m > n) ? m: n;

	Grid *maze;
	maze = new Grid(m, n, screenSize/gridSize);
	

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