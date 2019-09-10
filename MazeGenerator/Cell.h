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
<<<<<<< HEAD




#endif
=======
>>>>>>> upstream/master

