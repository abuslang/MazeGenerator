#ifndef GRID_H
#define GRID_H

#include "SFML/Graphics.hpp"

class Grid : public sf::Drawable
{
public:
	Grid();
	Grid(int m, int n, int s);	//create a m x n grid with cell sizes of s x s

	~Grid();
private:
	//The grid is gotta be drawable
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
};
#endif // !GRID_H
