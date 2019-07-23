#ifndef KRUSKALS_H
#define KRUSKALS_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"

class Kruskals : public BasicScreen
{
private:
	int numRows;
	int numCols;
	std::vector<std::tuple<int, int, int>> disjointSet;
	void DJSinit(int numRows, int numCols);
	int DJSfind(int row, int col);
	void DJSunion(int root1, int root2);

public:
	Kruskals();
	~Kruskals();

	int Run(sf::RenderWindow &window, Grid &grid);

};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

Kruskals::Kruskals() {}
Kruskals::~Kruskals() 
{
	//swap djs with empty vector, therefore deallocating it
	std::vector<std::tuple<int, int, int>>().swap(disjointSet);
}

void Kruskals::DJSinit(int numRows, int numCols)
{
	this->numRows = numRows;
	this->numCols = numCols;
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			disjointSet[row*numCols + col] = std::make_tuple(row, col, -1);
		}
	}
}//end DJSinit

int Kruskals::DJSfind(int row, int col) 
{
	if (std::get<2>(disjointSet[row*numCols + col]) <= -1)
	{
		return row * numCols + col;
	}

	//else
	DJSfind(row, col);
}//end DJSfind

void Kruskals::DJSunion(int root1, int root2) 
{
	//union by size
	//make the smaller tree a subtree of the larger
	//However, in this case, the sizes will be negative, so have to flip the comparison sign
	if (std::get<2>(disjointSet[root1]) > std::get<2>(disjointSet[root2]))
	{
		//add size of root1 to root2, then
		//make root1 a child of root2

		int newSize = std::get<2>(disjointSet[root1]) + std::get<2>(disjointSet[root2]);
		std::tuple<int, int, int> newRoot2 = std::make_tuple
		(
			std::get<0>(disjointSet[root2]),
			std::get<1>(disjointSet[root2]),
			newSize
		);
		std::tuple<int, int, int> newRoot1 = std::make_tuple
		(
			std::get<0>(disjointSet[root1]),
			std::get<1>(disjointSet[root1]),
			root2
		);
		disjointSet[root1].swap(newRoot1);
		disjointSet[root2].swap(newRoot2);
	}
	else
	{
		//add size of root1 to root2, then
		//make root2 a child of root1

		int newSize = std::get<2>(disjointSet[root1]) + std::get<2>(disjointSet[root2]);
		std::tuple<int, int, int> newRoot2 = std::make_tuple
		(
			std::get<0>(disjointSet[root2]),
			std::get<1>(disjointSet[root2]),
			root1
		);
		std::tuple<int, int, int> newRoot1 = std::make_tuple
		(
			std::get<0>(disjointSet[root1]),
			std::get<1>(disjointSet[root1]),
			newSize
		);
		disjointSet[root1].swap(newRoot1);
		disjointSet[root2].swap(newRoot2);
	}
}//end DJSunion


int Kruskals::Run(sf::RenderWindow &window, Grid &grid)
{

}//end run







#endif