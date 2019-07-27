/*
	This is the abstract class/interface for a "screen". Each screen needs to have a Run method that takes in a handle to a window.
	The Run Method can then draw stuff onto that window.
	The window can be passed from screen to screen by returning a number associated with a screen, and then switching to that screen in src.cpp
*/


#ifndef BASIC_SCREEN_H
#define BASIC_SCREEN_H
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

/////////////////
///odd indices should be maze generating screens,
///even indices should be maze solving screens
///menu should be index 0
////////////////

enum ScreenEnum
{
	MENU_SCREEN,
	RECURSIVE_BACKTRACKER_SCREEN,
	DFS_SCREEN,
	KRUSKALS_SCREEN,
	LAST_ENUM,
};

class Grid;

class BasicScreen
{
private:
public:
	sf::Font font;
	BasicScreen()
	{
		if (!font.loadFromFile("Gamegirl.ttf")) {
			// only execute if failed to load
			std::cout << "Font Failed to Load\n";
		}
	}
	virtual int Run(sf::RenderWindow &window, Grid &grid) = 0;
};

#endif //BASIC_SCREEN_H