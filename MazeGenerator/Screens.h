#ifndef SCREENS_H
#define SCREENS_H
#pragma once

/////////////////
///even indices should be maze generating screens,
///odd indices should be maze solving screens
///menu should be index 0
////////////////
enum ScreenEnum
{
	TEST_GRID_SCREEN = 1,
	RECURSIVE_BACKTRACKER_SCREEN = 2,
	DFS_SCREEN = 3,
};

//Basic Screen Class
#include "BasicScreen.h"

//Including each screen of application
#include "test.h"		//draws a green circly, just using as a test to make sure things work
#include "TestGrid.h"	//draws the entire grid, using it to see if grid setting up correctly
#include "RecursiveBacktracker.h"
#include "DFS.h"

#endif // SCREENS_H