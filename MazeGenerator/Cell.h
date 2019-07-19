#ifndef CELL_H
#define CELL_H
#pragma once

#include "SFML/Graphics.hpp"

enum PathEnum
{
	CELL_PATH_N = 0x01,		//00001
	CELL_PATH_E = 0x02,		//00010
	CELL_PATH_S = 0x04,		//00100
	CELL_PATH_W = 0x08,		//01000
	CELL_VISITED = 0x10,	//10000
};


class Cell : public sf::Drawable
{

private:
	int state;			//flag for whether its connected to any of its neighbors, and/or has been visited
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

};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

Cell::Cell(){}

Cell::Cell(int row, int col, int s) : rowIdx(row), colIdx(col), s(s)
{
	//set the positions and default values for the cell attributes
	state = 0;

	body.setSize(sf::Vector2f(s, s));
	body.setFillColor(sf::Color::Blue);
	body.setPosition(col * s, row * s);

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
	right.setPosition((col * s + s) - (s/5), row * s );
}//end constructor

void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(top);
	target.draw(bottom);
	target.draw(left);
	target.draw(right);
}//end draw

void Cell::setState(int s)
{
	//update state
	state = s; 

	//now change the attributes to match the state
	if ((state & CELL_VISITED) == CELL_VISITED)
	{
		//then the body color should be white
		body.setFillColor(sf::Color::White);
	}

	if ((state & CELL_PATH_E) == CELL_PATH_E)
	{
		//then remove east/right wall
		right.setFillColor(sf::Color::Transparent);
	}

	if ((state & CELL_PATH_N) == CELL_PATH_N)
	{
		//then remove north/top wall
		top.setFillColor(sf::Color::Transparent);
	}

	if ((state & CELL_PATH_W) == CELL_PATH_W)
	{
		//then remove west/left wall
		left.setFillColor(sf::Color::Transparent);
	}

	if ((state & CELL_PATH_S) == CELL_PATH_S)
	{
		//then remove west/left wall
		bottom.setFillColor(sf::Color::Transparent);
	}
}

int Cell::getState() { return state; }

int Cell::getColIdx() { return colIdx; }

int Cell::getRowIdx() { return rowIdx; }

int Cell::getSize() { return s; }


#endif

