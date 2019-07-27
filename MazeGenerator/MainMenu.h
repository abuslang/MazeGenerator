#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#pragma once

#include "BasicScreen.h"
#include "Grid.h"

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
	int getPressedItem();
};
// Menu.cpp --------------------------------------------------------------------------------------------------

MainMenu::MainMenu()
{
	if (!font.loadFromFile("Gamegirl.ttf")) {
		// only execute if failed to load
		std::cout << "oh no\n";
		exit(EXIT_FAILURE);
	}
	nameArr.push_back("Menu Screen");
	nameArr.push_back("Recursive Backtracker");
	nameArr.push_back("Depth First Search");
	nameArr.push_back("Kruskal's");

	title.setFont(font);
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(60);
	title.setPosition(0, 0);
	title.setString("Maze Generation and Solving");

	forceGen = false;
}

MainMenu::~MainMenu()
{
	std::vector<std::string>().swap(nameArr);
}

int MainMenu::Run(sf::RenderWindow &window, Grid &grid)
{

	window.setTitle("MainMenu Screen");
	bool Running = true;
	srand(time(NULL));

	sf::Text escPrompt;
	escPrompt.setFont(font);
	escPrompt.setFillColor(sf::Color::White);
	escPrompt.setCharacterSize(45);
	escPrompt.setString("Press Escape To Exit");
	escPrompt.setOrigin(escPrompt.getLocalBounds().width / 2, escPrompt.getLocalBounds().height / 2);
	escPrompt.setPosition(sf::Vector2f(window.getSize().x / 2, 40));

	sf::Event event;
	int r = (rand() % 256);
	int g = (rand() % 256);
	int b = (rand() % 256);

	while (Running)
	{
		window.clear();

		title.setFillColor(sf::Color( r*std::sin(time(NULL)), g*std::sin(time(NULL)), b*std::sin(time(NULL))));
		window.draw(title);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return (-1);
			if (event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape)
					return (-1);
				if(event.key.code == sf::Keyboard::Return)
					return getPressedItem();
				if (event.key.code == sf::Keyboard::Right)
				{
					if (!grid.getMazeGenFlag() || forceGen)
					{
					//incr to next generation algo
					}
					else
					{
					//incr to next solving algo

					}
				}
			}
		}

		if (!grid.getMazeGenFlag() || forceGen)
		{
			//if maze has not been generated, then prompt the user to select a generation algo
			drawGenScreen(window);
			forceGen = false;
		}
		else if (grid.getMazeGenFlag())
		{
			//else prompt the user for a maze solving algo OR ask if the user wants to regenerate
			drawSolveScreen(window);
		}



		window.draw(escPrompt);
		window.display();
	}

	//never reaches here
	return (-1);

}//end run

void MainMenu::drawGenScreen(sf::RenderWindow &window) 
{

}

#endif // !MAIN_MENU_H
