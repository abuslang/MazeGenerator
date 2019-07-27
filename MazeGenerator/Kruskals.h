#pragma once

#include "BasicScreen.h"

class Grid;

class Kruskals : public BasicScreen
{
private:

	struct DisjointSet
	{
	private:
		int numRows;
		int numCols;
		std::vector<std::tuple<int, int, int>> set;
	public:

		DisjointSet(int rows, int cols);
		~DisjointSet();

		int find(int idx);
		void Union(int root1, int root2);
		std::vector<std::tuple<int, int, int>> copy();
	};

public:
	~Kruskals();

	int Run(sf::RenderWindow &window, Grid &grid);
};
