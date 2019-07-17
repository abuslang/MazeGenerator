#ifndef CELL_H
#define CELL_H
#pragma once

#include "SFML/Graphics.hpp"

class Cell : public sf::Drawable
{

private:
	int state = 0x0;			//flag for whether its connected to any of its neighbors, and/or has been visited
	sf::RectangleShape body;	//main body of the cell
	sf::RectangleShape top;		//borders/walls of the cell
	sf::RectangleShape right;
	sf::RectangleShape bottom;
	sf::RectangleShape left;


public:
	Cell();
	Cell(int row, int col, int s);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};
//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later

Cell::Cell(){}

Cell::Cell(int row, int col, int s)
{
	//set the positions and default values for the cell attributes
	body.setSize(sf::Vector2f(s, s));
	body.setFillColor(sf::Color::Blue);
	body.setPosition(col * s, row * s);

	top.setSize(sf::Vector2f(s, s / 10));
	top.setFillColor(sf::Color::Black);
	top.setPosition(col * s, row * s);

	bottom.setSize(sf::Vector2f(s, s / 10));
	bottom.setFillColor(sf::Color::Black);
	bottom.setPosition(col * s, (row * s + s) - (s / 10));

	left.setSize(sf::Vector2f(s / 10, s));
	left.setFillColor(sf::Color::Black);
	left.setPosition(col * s, row * s);

	right.setSize(sf::Vector2f(s / 10, s));
	right.setFillColor(sf::Color::Black);
	right.setPosition((col * s + s) - (s/10), row * s );
}//end constructor


void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(top);
	target.draw(bottom);
	target.draw(left);
	target.draw(right);
}//end draw





#endif

