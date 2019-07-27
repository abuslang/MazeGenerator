
#pragma once

#include "BasicScreen.h"

class Grid;

class MainMenu : public BasicScreen
{
private:
	sf::Text title;
	int idx;
	std::vector<std::string> nameArr;
	bool forceGen;

public:
	MainMenu();
	~MainMenu();
	int Run(sf::RenderWindow &window, Grid &grid);
	void drawGenScreen(sf::RenderWindow &window);
	void drawSolveScreen(sf::RenderWindow &window);
};
