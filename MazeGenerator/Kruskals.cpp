#include "Kruskals.h"
<<<<<<< HEAD

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
	disjointSet.resize(numRows*numCols);
=======
#include <iostream>
#include "Cell.h"
#include "Grid.h"




Kruskals::DisjointSet::DisjointSet(int rows, int cols) : numRows(rows), numCols(cols)
{
	set.resize(numRows*numCols);
>>>>>>> upstream/master

	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
<<<<<<< HEAD
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

int Kruskals::DJSfind(int idx)
{
	if (std::get<2>(disjointSet[idx]) <= -1)
=======
			set[row*numCols + col] = std::make_tuple(row, col, -1);
		}
	}
}//end constructor

Kruskals::DisjointSet::~DisjointSet()
{
	std::vector<std::tuple<int, int, int>>().swap(set);
}//end destructor

int Kruskals::DisjointSet::find(int idx)
{
	if (std::get<2>(set[idx]) <= -1)
>>>>>>> upstream/master
	{
		return idx;
	}
	else
	{
<<<<<<< HEAD
		return DJSfind(std::get<2>(disjointSet[idx]));
	}
}//end DJSfind

void Kruskals::DJSunion(int root1, int root2)
{
	//union by size
	//make the smaller tree a subtree of the larger
	//However, in this case, the sizes will be negative, so have to flip the comparison sign
	if (std::get<2>(disjointSet[root1]) > std::get<2>(disjointSet[root2]))
=======
		return find(std::get<2>(set[idx]));
	}
}//end find

void Kruskals::DisjointSet::Union(int root1, int root2)
{

	//union by size
	//make the smaller tree a subtree of the larger
	//However, in this case, the sizes will be negative, so have to flip the comparison sign
	if (std::get<2>(set[root1]) > std::get<2>(set[root2]))
>>>>>>> upstream/master
	{
		//add size of root1 to root2, then
		//make root1 a child of root2

<<<<<<< HEAD
		int newSize = std::get<2>(disjointSet[root1]) + std::get<2>(disjointSet[root2]);
		std::tuple<int, int, int> newRoot2 = std::make_tuple
		(
			std::get<0>(disjointSet[root2]),
			std::get<1>(disjointSet[root2]),
=======
		int newSize = std::get<2>(set[root1]) + std::get<2>(set[root2]);
		std::tuple<int, int, int> newRoot2 = std::make_tuple
		(
			std::get<0>(set[root2]),
			std::get<1>(set[root2]),
>>>>>>> upstream/master
			newSize
		);
		std::tuple<int, int, int> newRoot1 = std::make_tuple
		(
<<<<<<< HEAD
			std::get<0>(disjointSet[root1]),
			std::get<1>(disjointSet[root1]),
			root2
		);
		disjointSet[root1].swap(newRoot1);
		disjointSet[root2].swap(newRoot2);
=======
			std::get<0>(set[root1]),
			std::get<1>(set[root1]),
			root2
		);
		set[root1].swap(newRoot1);
		set[root2].swap(newRoot2);
>>>>>>> upstream/master
	}
	else
	{
		//add size of root1 to root2, then
		//make root2 a child of root1

<<<<<<< HEAD
		int newSize = std::get<2>(disjointSet[root1]) + std::get<2>(disjointSet[root2]);
		std::tuple<int, int, int> newRoot2 = std::make_tuple
		(
			std::get<0>(disjointSet[root2]),
			std::get<1>(disjointSet[root2]),
=======
		int newSize = std::get<2>(set[root1]) + std::get<2>(set[root2]);
		std::tuple<int, int, int> newRoot2 = std::make_tuple
		(
			std::get<0>(set[root2]),
			std::get<1>(set[root2]),
>>>>>>> upstream/master
			root1
		);
		std::tuple<int, int, int> newRoot1 = std::make_tuple
		(
<<<<<<< HEAD
			std::get<0>(disjointSet[root1]),
			std::get<1>(disjointSet[root1]),
			newSize
		);
		disjointSet[root1].swap(newRoot1);
		disjointSet[root2].swap(newRoot2);
	}
}//end DJSunion

=======
			std::get<0>(set[root1]),
			std::get<1>(set[root1]),
			newSize
		);
		set[root1].swap(newRoot1);
		set[root2].swap(newRoot2);
	}
}//end union

std::vector<std::tuple<int, int, int>>  Kruskals::DisjointSet::copy()
{
	return set;
}



///////////////////////////////////////////////////////////////////////////////////////////////
Kruskals::~Kruskals() {}
>>>>>>> upstream/master

int Kruskals::Run(sf::RenderWindow &window, Grid &grid)
{
	window.setTitle("Kruskals Screen");
	srand(time(NULL));
	grid.resetGeneration();

	bool Running = true;
	sf::Event event;


	int wallsDown = 0;
<<<<<<< HEAD

	//initialize the Disjoint set with default values
	DJSinit(grid.getNumRows(), grid.getNumCols());

	//make a vector of cells that we will be picking from
	std::vector<std::tuple<int, int, int>> cells = disjointSet;
=======
	int cellsRemoved = 0;

	//initialize the Disjoint set with default values
	DisjointSet disjointSet(grid.getNumRows(), grid.getNumCols());

	//make a vector of cells that we will be picking from
	std::vector<std::tuple<int, int, int>> cells = disjointSet.copy();

	bool paused = false;
	sf::Text pausedPrompt;

	pausedPrompt.setFont(font);
	pausedPrompt.setString("!PAUSED!");
	pausedPrompt.setCharacterSize(60);
	pausedPrompt.setOrigin(pausedPrompt.getLocalBounds().width / 2, pausedPrompt.getLocalBounds().height / 2);
	pausedPrompt.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	sf::Text finishedPrompt;
	finishedPrompt.setFont(font);
	finishedPrompt.setString("Press Return\nTo Continue");
	finishedPrompt.setCharacterSize(60);
	finishedPrompt.setOrigin(finishedPrompt.getLocalBounds().width / 2, finishedPrompt.getLocalBounds().height / 2);
	finishedPrompt.setPosition(window.getSize().x / 2, window.getSize().y / 2);
>>>>>>> upstream/master

	while (Running)
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return (-1);
<<<<<<< HEAD
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					return (0);
=======
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return && grid.getMazeGenFlag())
					return (MENU_SCREEN);
				else if (event.key.code == sf::Keyboard::Space)
					paused = !paused;
>>>>>>> upstream/master
			}
		}


<<<<<<< HEAD
		if (wallsDown < (numCols * numRows) - 1)
		{
			std::cout << "Kruskals is generating		\r";
			std::vector<int> neighbours;
			int randIdx = rand() % cells.size();
			std::tuple<int, int, int> randCell = cells[randIdx];
			auto offset = [&](int row, int col)
			{
				return (std::get<0>(randCell) + row) * numCols + (std::get<1>(randCell) + col);
			};


			//now check for neighbors in N, S, E and W directions

			//if the cell is anywhere BUT row 0, then the cell has NORTH neighbor
			if (std::get<0>(randCell) > 0 && (grid.getState(offset(0, 0)) & PATH_N) == 0x0)
				if (DJSfind(offset(0, 0)) != DJSfind(offset(-1, 0)))
					neighbours.push_back(0);

			//if the cell is anywhere but the last column, then the cell has EAST neighbor
			if (std::get<1>(randCell) < (grid.getNumCols() - 1) && (grid.getState(offset(0, 0)) & PATH_E) == 0x0)
				if (DJSfind(offset(0, 0)) != DJSfind(offset(0, 1)))
					neighbours.push_back(1);

			//if the cell is anywhere but the bottom row, then it has SOUTH neighbor
			if (std::get<0>(randCell) < (grid.getNumRows() - 1) && (grid.getState(offset(0, 0)) & PATH_S) == 0x0)
				if (DJSfind(offset(0, 0)) != DJSfind(offset(1, 0)))
					neighbours.push_back(2);

			//if the cell is anywhere but the 1st column, then it has WEST neighbor
			if (std::get<1>(randCell) > 0 && (grid.getState(offset(0, 0)) & PATH_W) == 0x0)
				if (DJSfind(offset(0, 0)) != DJSfind(offset(0, -1)))
					neighbours.push_back(3);

			if (!neighbours.empty())
			{
				//pick random edge and break down the wall
				int edge = neighbours[rand() % neighbours.size()];
				switch (edge)
				{
				case 0:	//NORTH
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_N | GEN_VISITED);
					grid.setState(offset(-1, 0), grid.getState(offset(-1, 0)) | PATH_S | GEN_VISITED);
					DJSunion(DJSfind(offset(0, 0)), DJSfind(offset(-1, 0)));
					break;

				case 1:	//EAST
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_E | GEN_VISITED);
					grid.setState(offset(0, 1), grid.getState(offset(0, 1)) | PATH_W | GEN_VISITED);
					DJSunion(DJSfind(offset(0, 0)), DJSfind(offset(0, 1)));
					break;

				case 2:	//SOUTH
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_S | GEN_VISITED);
					grid.setState(offset(1, 0), grid.getState(offset(1, 0)) | PATH_N | GEN_VISITED);
					DJSunion(DJSfind(offset(0, 0)), DJSfind(offset(1, 0)));
					break;

				case 3:	//WEST
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_W | GEN_VISITED);
					grid.setState(offset(0, -1), grid.getState(offset(0, -1)) | PATH_E | GEN_VISITED);
					DJSunion(DJSfind(offset(0, 0)), DJSfind(offset(0, -1)));
					break;
				}
				wallsDown++;
			}
			else
			{
				//remove the cell from cell list
				cells.erase(cells.begin() + randIdx);
			}



		}// end algo if
		else
		{
			std::cout << "Kruskals is done			\r";
		}

		window.clear();
		window.draw(grid);
=======
		if (!paused)
		{
			if (wallsDown < (grid.getNumRows() * grid.getNumCols()) - 1)
			{
				std::cout << "Kruskals is generating		\r";
				std::vector<int> neighbours;
				int randIdx = rand() % cells.size();
				std::tuple<int, int, int> randCell = cells[randIdx];
				auto offset = [&](int row, int col)
				{
					return (std::get<0>(randCell) + row) * grid.getNumCols() + (std::get<1>(randCell) + col);
				};


				//now check for neighbors in N, S, E and W directions

				//if the cell is anywhere BUT row 0, then the cell has NORTH neighbor
				if (std::get<0>(randCell) > 0 && (grid.getState(offset(0, 0)) & PATH_N) == 0x0)
					if (disjointSet.find(offset(0, 0)) != disjointSet.find(offset(-1, 0)))
						neighbours.push_back(0);

				//if the cell is anywhere but the last column, then the cell has EAST neighbor
				if (std::get<1>(randCell) < (grid.getNumCols() - 1) && (grid.getState(offset(0, 0)) & PATH_E) == 0x0)
					if (disjointSet.find(offset(0, 0)) != disjointSet.find(offset(0, 1)))
						neighbours.push_back(1);

				//if the cell is anywhere but the bottom row, then it has SOUTH neighbor
				if (std::get<0>(randCell) < (grid.getNumRows() - 1) && (grid.getState(offset(0, 0)) & PATH_S) == 0x0)
					if (disjointSet.find(offset(0, 0)) != disjointSet.find(offset(1, 0)))
						neighbours.push_back(2);

				//if the cell is anywhere but the 1st column, then it has WEST neighbor
				if (std::get<1>(randCell) > 0 && (grid.getState(offset(0, 0)) & PATH_W) == 0x0)
					if (disjointSet.find(offset(0, 0)) != disjointSet.find(offset(0, -1)))
						neighbours.push_back(3);

				if (!neighbours.empty())
				{
					//pick random edge and break down the wall
					int edge = neighbours[rand() % neighbours.size()];
					switch (edge)
					{
					case 0:	//NORTH
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_N | GEN_VISITED);
						grid.setState(offset(-1, 0), grid.getState(offset(-1, 0)) | PATH_S | GEN_VISITED);
						disjointSet.Union(disjointSet.find(offset(0, 0)), disjointSet.find(offset(-1, 0)));
						break;

					case 1:	//EAST
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_E | GEN_VISITED);
						grid.setState(offset(0, 1), grid.getState(offset(0, 1)) | PATH_W | GEN_VISITED);
						disjointSet.Union(disjointSet.find(offset(0, 0)), disjointSet.find(offset(0, 1)));
						break;

					case 2:	//SOUTH
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_S | GEN_VISITED);
						grid.setState(offset(1, 0), grid.getState(offset(1, 0)) | PATH_N | GEN_VISITED);
						disjointSet.Union(disjointSet.find(offset(0, 0)), disjointSet.find(offset(1, 0)));
						break;

					case 3:	//WEST
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_W | GEN_VISITED);
						grid.setState(offset(0, -1), grid.getState(offset(0, -1)) | PATH_E | GEN_VISITED);
						disjointSet.Union(disjointSet.find(offset(0, 0)), disjointSet.find(offset(0, -1)));
						break;
					}
					wallsDown++;
				}
				else
				{
					//remove the cell from cell list
					cells.erase(cells.begin() + randIdx);
					cellsRemoved++;

				}



			}// end algo if
			else
			{
				std::cout << "Kruskals is done			\r";
				grid.setMazeGenFlag(true);
			}
		}//end if paused

		window.clear();
		window.draw(grid);
		if (grid.getMazeGenFlag())
		{
			finishedPrompt.setFillColor(sf::Color(128 * std::sin(time(NULL)), 255 * std::sin(time(NULL)), 128 * std::cos(time(NULL))));
			window.draw(finishedPrompt);

		}
		else if (paused)
		{
			pausedPrompt.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			window.draw(pausedPrompt);
		}
>>>>>>> upstream/master
		window.display();
	}

	return -1;

}//end run