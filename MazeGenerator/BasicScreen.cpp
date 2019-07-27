#include "BasicScreen.h"
#include <iostream>


BasicScreen::BasicScreen()
{
	if (!font.loadFromFile("Gamegirl.ttf")) {
		// only execute if failed to load
		std::cout << "Font Failed to Load\n";
	}
}
