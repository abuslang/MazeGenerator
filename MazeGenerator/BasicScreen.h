/*
	This is the abstract class/interface for a "screen". Each screen needs to have a Run method that takes in a handle to a window.
	The Run Method can then draw stuff onto that window.
	The window can be passed from screen to screen by returning a number associated with a screen, and then switching to that screen in src.cpp
*/


#ifndef BASIC_SCREEN_H
#define BASIC_SCREEN_H
#pragma once
#include "SFML/Graphics.hpp"

class Grid;

class BasicScreen
{
public:
	virtual int Run(sf::RenderWindow &window, Grid &grid) = 0;
};

#endif //BASIC_SCREEN_H