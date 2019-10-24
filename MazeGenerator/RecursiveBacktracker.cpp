<<<<<<< HEAD
#include "RecursiveBacktracker.h"


RecursiveBacktracker::RecursiveBacktracker()
{
}

RecursiveBacktracker::~RecursiveBacktracker()
{
}
=======
/*
	Desc:
	The Recursive Backtracker selects a random unvisited neighboring cells and visits it. The algo will continue 
	visiting unvisited neighbors until it runs out of unvisited neighboring cells. There the algo wil backtrack to a cell
	which has an unvisited neighboring cell and continues. The algo continues until there are no more unvisited cells.
*/

#include "RecursiveBacktracker.h"
#include "Cell.h"
#include "Grid.h"
#include <stack>
#include <iostream>


RecursiveBacktracker::~RecursiveBacktracker(){}
>>>>>>> upstream/master

int RecursiveBacktracker::Run(sf::RenderWindow &window, Grid &grid)
{
	window.setTitle("Recursive Backtracker Screen");
	srand(time(NULL));
	grid.resetGeneration();

	bool Running = true;
	sf::Event event;
	int visitedCount = 0;
	std::stack<std::pair<int, int>> stack;	//holds a stack of indices of the cells

	//start from random cell
	int row = rand() % (grid.getNumRows());
	int col = rand() % (grid.getNumCols());
	stack.push(std::make_pair(row, col));
	grid.setState(row, col, GEN_VISITED);
	visitedCount = 1;

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======

>>>>>>> a35f1556c5fb1ffecc1f355fd7eb7211a0d777c4
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


	//lambda function that helps out finding location of a cell relative to a specified cell
	auto offset = [&](int row, int col)
	{
		return (stack.top().first + row) * grid.getNumCols() + (stack.top().second + col);
	};

	//render loop
	while (Running)
	{
<<<<<<< HEAD
=======

>>>>>>> upstream/master
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return (-1);
			if (event.type == sf::Event::KeyPressed)
			{
<<<<<<< HEAD
				if (event.key.code == sf::Keyboard::Escape)
					return (0);
			}
		}



		if (!stack.empty())
		{
			//this is to reset the color of the cell at the top of the stack
			grid.setState(offset(0, 0), grid.getState(offset(0, 0)));
		}

		//the algo is in this if
		//it's inside an if b/c we want to se the maze generate in realtime
		if (visitedCount < (grid.getNumCols() * grid.getNumRows()))
		{
			// Create a set of unvisted neighbours
			std::vector<int> neighbours;

			//now check for neighbors in N, S, E and W directions

			//if the cell is anywhere BUT row 0, then the cell has NORTH neighbor
			if (stack.top().first > 0 && ((grid.getState(offset(-1, 0)) & GEN_VISITED) == 0x0))
				neighbours.push_back(0);
			//if the cell is anywhere but the last column, then the cell has EAST neighbor
			if (stack.top().second < (grid.getNumCols() - 1) && ((grid.getState(offset(0, 1)) & GEN_VISITED) == 0x0))
				neighbours.push_back(1);
			//if the cell is anywhere but the bottom row, then it has SOUTH neighbor
			if (stack.top().first < (grid.getNumRows() - 1) && ((grid.getState(offset(1, 0)) & GEN_VISITED) == 0x0))
				neighbours.push_back(2);
			//if the cell is anywhere but the 1st column, then it has WEST neighbor
			if (stack.top().second > 0 && ((grid.getState(offset(0, -1)) & GEN_VISITED) == 0x0))
				neighbours.push_back(3);

			//now the neighbor vector may not be populated with unvisited neighbors
			if (!neighbours.empty())
			{

				// Choose one available neighbour at random
				int nextCellDir = neighbours[rand() % neighbours.size()];

				switch (nextCellDir)
				{
				case 0:	//NORTH
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_N);
					grid.setState(offset(-1, 0), grid.getState(offset(-1, 0)) | PATH_S);
					stack.push(std::make_pair((stack.top().first - 1), (stack.top().second + 0)));
					break;

				case 1:	//EAST
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_E);
					grid.setState(offset(0, 1), grid.getState(offset(0, 1)) | PATH_W);
					stack.push(std::make_pair((stack.top().first + 0), (stack.top().second + 1)));
					break;

				case 2:	//SOUTH
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_S);
					grid.setState(offset(1, 0), grid.getState(offset(1, 0)) | PATH_N);
					stack.push(std::make_pair((stack.top().first + 1), (stack.top().second + 0)));
					break;

				case 3:	//WEST
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_W);
					grid.setState(offset(0, -1), grid.getState(offset(0, -1)) | PATH_E);
					stack.push(std::make_pair((stack.top().first + 0), (stack.top().second - 1)));
					break;
				}//end switch

				//make neighbor cell visited
				grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | GEN_VISITED);

				//make the top of the stack distinct so we can see it moving
				grid.setColor(offset(0, 0), sf::Color::Red);
				visitedCount++;
			}
			else
			{
				stack.pop();

				//make the top of the stack distinct so we can see it moving
				grid.setColor(offset(0, 0), sf::Color::Red);
			}
		}//end algo if

		window.clear();
		window.draw(grid);
=======
				if (event.key.code == sf::Keyboard::Return && grid.getMazeGenFlag())
					return (MENU_SCREEN);
				if (event.key.code == sf::Keyboard::Space)
					paused = !paused;
			}
		}

		if (!paused)
		{
			if (!stack.empty())
			{
				//this is to reset the color of the cell at the top of the stack
				grid.setState(offset(0, 0), grid.getState(offset(0, 0)));
			}

			//the algo is in this if
			//it's inside an if b/c we want to see the maze generate frame by frame
			if (visitedCount < (grid.getNumCols() * grid.getNumRows()))
			{
				std::cout << "Recursive Backtracker is generating	\r";

				// Create a set of unvisted neighbours
				std::vector<int> neighbours;

				//now check for neighbors in N, S, E and W directions

				//if the cell is anywhere BUT row 0, then the cell has NORTH neighbor
				if (stack.top().first > 0 && ((grid.getState(offset(-1, 0)) & GEN_VISITED) == 0x0))
					neighbours.push_back(0);
				//if the cell is anywhere but the last column, then the cell has EAST neighbor
				if (stack.top().second < (grid.getNumCols() - 1) && ((grid.getState(offset(0, 1)) & GEN_VISITED) == 0x0))
					neighbours.push_back(1);
				//if the cell is anywhere but the bottom row, then it has SOUTH neighbor
				if (stack.top().first < (grid.getNumRows() - 1) && ((grid.getState(offset(1, 0)) & GEN_VISITED) == 0x0))
					neighbours.push_back(2);
				//if the cell is anywhere but the 1st column, then it has WEST neighbor
				if (stack.top().second > 0 && ((grid.getState(offset(0, -1)) & GEN_VISITED) == 0x0))
					neighbours.push_back(3);

				//now the neighbor vector may not be populated with unvisited neighbors
				if (!neighbours.empty())
				{

					// Choose one available neighbour at random
					int nextCellDir = neighbours[rand() % neighbours.size()];

					switch (nextCellDir)
					{
					case 0:	//NORTH
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_N);
						grid.setState(offset(-1, 0), grid.getState(offset(-1, 0)) | PATH_S);
						stack.push(std::make_pair((stack.top().first - 1), (stack.top().second + 0)));
						break;

					case 1:	//EAST
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_E);
						grid.setState(offset(0, 1), grid.getState(offset(0, 1)) | PATH_W);
						stack.push(std::make_pair((stack.top().first + 0), (stack.top().second + 1)));
						break;

					case 2:	//SOUTH
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_S);
						grid.setState(offset(1, 0), grid.getState(offset(1, 0)) | PATH_N);
						stack.push(std::make_pair((stack.top().first + 1), (stack.top().second + 0)));
						break;

					case 3:	//WEST
						grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | PATH_W);
						grid.setState(offset(0, -1), grid.getState(offset(0, -1)) | PATH_E);
						stack.push(std::make_pair((stack.top().first + 0), (stack.top().second - 1)));
						break;
					}//end switch

					//make neighbor cell visited
					grid.setState(offset(0, 0), grid.getState(offset(0, 0)) | GEN_VISITED);

					//make the top of the stack distinct so we can see it moving
					grid.setColor(offset(0, 0), sf::Color::Red);
					visitedCount++;
				}
				else
				{
					stack.pop();

					//make the top of the stack distinct so we can see it moving
					grid.setColor(offset(0, 0), sf::Color::Red);
				}
			}//end algo if
			else
			{
				std::cout << "Recursive Backtracker is done	\r";
				grid.setMazeGenFlag(true);
			}
		}//end if !paused


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
	}//end render loop

	//never reaches here
	return (-1);

}