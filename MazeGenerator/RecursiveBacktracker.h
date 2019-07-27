/*

*/
#pragma once
#include "BasicScreen.h"

class Grid;

class RecursiveBacktracker : public BasicScreen
{
public:
	~RecursiveBacktracker();
	int Run(sf::RenderWindow &window, Grid &grid);
};
