#ifndef KRUSKALS_H
#define KRUSKALS_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"
#include <iostream>


class Kruskals : public BasicScreen
{
private:
	int numRows;
	int numCols;
	std::vector<std::tuple<int, int, int>> disjointSet;
	void DJSinit(int numRows, int numCols);
	int DJSfind(int row, int col);
	int DJSfind(int idx);
	void DJSunion(int root1, int root2);

public:
	Kruskals();
	~Kruskals();

	int Run(sf::RenderWindow &window, Grid &grid);

};







#endif