/*
Desc:
This is a basic main menu that lets the user choose the Maze Generation and Solution algorithms.
The menu looks at the status of the Maze (whether it has been generated or not) to decide what to menu to display.
*/

#include "MainMenu.h"
#include <iostream>
#include "Grid.h"

MainMenu::MainMenu()
{
	if (!font.loadFromFile("Gamegirl.ttf")) {
		// only execute if failed to load
		std::cout << "oh no\n";
		exit(EXIT_FAILURE);
	}
	nameArr.push_back("Recursive Backtracker");
	nameArr.push_back("Depth First Search");
	nameArr.push_back("Kruskal's");

	title.setFont(font);
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(35);
	title.setString("Maze Generation and Solving");
	title.setStyle(sf::Text::Bold);
	title.setOrigin(title.getLocalBounds().width / 2, 0);

	forceGen = false;
}

MainMenu::~MainMenu()
{
	//free the vector memory
	std::vector<std::string>().swap(nameArr);
}

int MainMenu::Run(sf::RenderWindow &window, Grid &grid)
{

	window.setTitle("MainMenu Screen");
	bool Running = true;
	srand(time(NULL));

	sf::Text escPrompt;
	escPrompt.setFont(font);
	escPrompt.setFillColor(sf::Color::Yellow);
	escPrompt.setCharacterSize(20);
	escPrompt.setString("Press Escape To Exit");
	escPrompt.setOrigin(escPrompt.getLocalBounds().width / 2, 0);
	escPrompt.setPosition(sf::Vector2f(window.getSize().x / 2, .95 * window.getSize().y));
	title.setPosition(sf::Vector2f(window.getSize().x / 2, 0));


	sf::Event event;
	idx = 0;

	while (Running)
	{
		window.clear();

		title.setFillColor(sf::Color(128 * std::sin(time(NULL)), 255 * std::sin(time(NULL)), 128 * std::cos(time(NULL))));
		window.draw(title);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return (-1);
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					return (-1);
				else if (event.key.code == sf::Keyboard::Backspace)
					forceGen = true;
				else if (event.key.code == sf::Keyboard::Return)
				{
					forceGen = false;
					return idx;
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					if (idx + 2 < LAST_ENUM)
					{
						idx += 2;
					}
					else
					{
						std::cout << "idx will be out of bounds		\r";
					}

				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					if (idx - 2 >= 0)
					{
						idx -= 2;
					}
					else
					{
						std::cout << "idx will be out of bounds		\r";
					}

				}
			}//end keyPressed event
		}



		if (!grid.getMazeGenFlag() || forceGen)
		{
			//if maze has not been generated, then prompt the user to select a generation algo

			//make sure idx is even
			if (idx % 2 != 0)
				idx = 0;
			drawGenScreen(window);
		}
		else if (grid.getMazeGenFlag())
		{
			//make sure idx is odd
			if (idx % 2 == 0)
				idx = 1;
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
	sf::Text subTitle;
	subTitle.setFont(font);
	subTitle.setFillColor(sf::Color::White);
	subTitle.setCharacterSize(30);
	subTitle.setString("Maze Generation Algorithms");
	subTitle.setStyle(sf::Text::Underlined | sf::Text::Regular);
	subTitle.setOrigin(subTitle.getLocalBounds().width / 2, 0);
	subTitle.setPosition(sf::Vector2f(window.getSize().x / 2, .25 * window.getSize().y));

	std::string str;
	str = "<- " + nameArr[idx] + " ->";
	sf::Text algo;
	algo.setFont(font);
	algo.setFillColor(sf::Color::White);
	algo.setCharacterSize(30);
	algo.setString(str);
	algo.setOrigin(algo.getLocalBounds().width / 2, 0);
	algo.setPosition(sf::Vector2f(window.getSize().x / 2, .5 * window.getSize().y));

	window.draw(subTitle);
	window.draw(algo);
}//end draw gen screen

void MainMenu::drawSolveScreen(sf::RenderWindow &window)
{
	sf::Text subTitle;
	subTitle.setFont(font);
	subTitle.setFillColor(sf::Color::White);
	subTitle.setCharacterSize(30);
	subTitle.setString("Maze Solving Algorithms");
	subTitle.setStyle(sf::Text::Underlined | sf::Text::Regular);
	subTitle.setOrigin(subTitle.getLocalBounds().width / 2, 0);
	subTitle.setPosition(sf::Vector2f(window.getSize().x / 2, .25 * window.getSize().y));

	std::string str;
	str = "<- " + nameArr[idx] + " ->";
	sf::Text algo;
	algo.setFont(font);
	algo.setFillColor(sf::Color::White);
	algo.setCharacterSize(30);
	algo.setString(str);
	algo.setOrigin(algo.getLocalBounds().width / 2, 0);
	algo.setPosition(sf::Vector2f(window.getSize().x / 2, .5 * window.getSize().y));

	sf::Text forceGenPrompt;
	forceGenPrompt.setString("Press Backspace to Regenerate Maze");
	forceGenPrompt.setFont(font);
	forceGenPrompt.setFillColor(sf::Color::Green);
	forceGenPrompt.setCharacterSize(25);
	forceGenPrompt.setStyle(sf::Text::Italic | sf::Text::Regular);
	forceGenPrompt.setOrigin(forceGenPrompt.getLocalBounds().width / 2, 0);
	forceGenPrompt.setPosition(sf::Vector2f(window.getSize().x / 2, .75 * window.getSize().y));

	window.draw(subTitle);
	window.draw(algo);
	window.draw(forceGenPrompt);
}