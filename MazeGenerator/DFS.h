#pragma once
#include "BasicScreen.h"

class Grid;

class DFS : public BasicScreen
{
private:
public:
	~DFS();
	int Run(sf::RenderWindow &window, Grid &grid);

};
