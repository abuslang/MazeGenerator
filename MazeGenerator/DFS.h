#ifndef DFS_H
#define DFS_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"
#include<stack>

class DFS : public BasicScreen
{
private:
public:
	DFS();
	~DFS();
	int Run(sf::RenderWindow &window, Grid &grid);

};

#endif // !DFH_H
