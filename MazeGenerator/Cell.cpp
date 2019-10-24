/*
Desc:
	This is the Cell class. It has the usual getter and setter methods, and also has methods for drawing the cell onto the screen.
	The Cell class also has a state attribute which can be used to keep track of the neighbors it has.
*/

#include "Cell.h"

>>>>>>> upstream/master
Cell::Cell() {}

Cell::Cell(int row, int col, int s) : rowIdx(row), colIdx(col), s(s)
{
<<<<<<< HEAD
=======
	int thickness = 7;
>>>>>>> upstream/master
	//set the positions and default values for the cell attributes
	state = (int)0x00000;

	body.setSize(sf::Vector2f(s, s));
	body.setFillColor(sf::Color::Blue);
	body.setPosition(col * s, row * s);

<<<<<<< HEAD
	top.setSize(sf::Vector2f(s, s / 5));
	top.setFillColor(sf::Color::Black);
	top.setPosition(col * s, row * s);

	bottom.setSize(sf::Vector2f(s, s / 5));
	bottom.setFillColor(sf::Color::Black);
	bottom.setPosition(col * s, (row * s + s) - (s / 5));

	left.setSize(sf::Vector2f(s / 5, s));
	left.setFillColor(sf::Color::Black);
	left.setPosition(col * s, row * s);

	right.setSize(sf::Vector2f(s / 5, s));
	right.setFillColor(sf::Color::Black);
	right.setPosition((col * s + s) - (s / 5), row * s);
=======
	top.setSize(sf::Vector2f(s, s / thickness));
	top.setFillColor(sf::Color::Black);
	top.setPosition(col * s, row * s);

	bottom.setSize(sf::Vector2f(s, s / thickness));
	bottom.setFillColor(sf::Color::Black);
	bottom.setPosition(col * s, (row * s + s) - (s / thickness));

	left.setSize(sf::Vector2f(s / thickness, s));
	left.setFillColor(sf::Color::Black);
	left.setPosition(col * s, row * s);

	right.setSize(sf::Vector2f(s / thickness, s));
	right.setFillColor(sf::Color::Black);
	right.setPosition((col * s + s) - (s / thickness), row * s);
>>>>>>> upstream/master
}//end constructor

void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(top);
	target.draw(bottom);
	target.draw(left);
	target.draw(right);
}//end draw


//accessor methods

int Cell::getState() { return state; }

int Cell::getColIdx() { return colIdx; }

int Cell::getRowIdx() { return rowIdx; }

int Cell::getSize() { return s; }

//mutator methods
void Cell::setColor(sf::Color color)
{
	body.setFillColor(color);
}

void Cell::setState(int s)
{
	//update state
	state = s;

	//now change the attributes to match the state

	if ((state & GEN_VISITED) == GEN_VISITED)
		//then the body color should be white
		body.setFillColor(sf::Color::White);
	else
		body.setFillColor(sf::Color::Blue);


	if ((state & PATH_E) == PATH_E)
		//then remove east/right wall
		right.setFillColor(sf::Color::Transparent);
	else
		right.setFillColor(sf::Color::Black);


	if ((state & PATH_N) == PATH_N)
		//then remove north/top wall
		top.setFillColor(sf::Color::Transparent);
	else
		top.setFillColor(sf::Color::Black);


	if ((state & PATH_W) == PATH_W)
		//then remove west/left wall
		left.setFillColor(sf::Color::Transparent);
	else
		left.setFillColor(sf::Color::Black);


	if ((state & PATH_S) == PATH_S)
		//then remove west/left wall
		bottom.setFillColor(sf::Color::Transparent);
	else
		bottom.setFillColor(sf::Color::Black);
}

<<<<<<< HEAD
=======

