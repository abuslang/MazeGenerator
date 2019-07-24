#ifndef CELL_H
#define CELL_H
#pragma once

#include "SFML/Graphics.hpp"

enum
{
	PATH_N = 0x01,		//000001
	PATH_E = 0x02,		//000010
	PATH_S = 0x04,		//000100
	PATH_W = 0x08,		//001000
	GEN_VISITED = 0x10,	//010000	//visited flag used during generation stage
	SOL_VISITED = 0x20,	//100000	//visited flag used during solution stage
};


class Cell : public sf::Drawable
{

private:
	int state;					//flag for whether its connected to any of its neighbors, and/or has been visited
	sf::RectangleShape body;	//main body of the cell
	sf::RectangleShape top;		//borders/walls of the cell
	sf::RectangleShape right;
	sf::RectangleShape bottom;
	sf::RectangleShape left;
	int rowIdx;					//what row it's in
	int colIdx;					//what col it's in 
	int s;						//size of cell


public:
	Cell();
	Cell(int row, int col, int s);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	//accessor methods
	int getState();
	int getRowIdx();
	int getColIdx();
	int getSize();

	//mutator methods
	void setState(int s);
	void setColor(sf::Color color);

};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

Cell::Cell(){}

Cell::Cell(int row, int col, int s) : rowIdx(row), colIdx(col), s(s)
{
	int thickness = 7;
	//set the positions and default values for the cell attributes
	state = (int)0x00000;

	body.setSize(sf::Vector2f(s, s));
	body.setFillColor(sf::Color::Blue);
	body.setPosition(col * s, row * s);

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
	right.setPosition((col * s + s) - (s/thickness), row * s );
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



#endif

