/*
	This is a test screen i copied from the sfml website and changed it a bit.
	it shows how this "screen" system will flow.
*/

#ifndef TEST_H
#define TEST_H
#pragma once

#include "cScreen.h"

class Test : public cScreen
{
private:
public:
	Test();
	virtual int Run(sf::RenderWindow &App);
};

//------------------------------------------------------------
//TODO: move this stuff to a .cpp file later


Test::Test() {}

int Test::Run(sf::RenderWindow &App)
{
	bool Running = true;
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (Running)
	{
		sf::Event event;
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return -1;
		}

		App.clear();
		App.draw(shape);
		App.display();
	}

	//never reaches here
	return -1;
}

#endif // !TEST_H


