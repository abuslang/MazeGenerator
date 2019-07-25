#ifndef RECURSIVE_BACKTRACKER_H
#define RECURSIVE_BACKTRACKER_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"
#include <stack>

class RecursiveBacktracker : public BasicScreen
{

private:
public:
	RecursiveBacktracker();
	~RecursiveBacktracker();
	int Run(sf::RenderWindow &window, Grid &grid);
};


#endif