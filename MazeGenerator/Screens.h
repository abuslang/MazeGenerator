#ifndef SCREENS_H
#define SCREENS_H
#pragma once

enum ScreenEnum
{
	TEST_SCREEN = 0,
	TEST_GRID_SCREEN = 1
};

//Basic Screen Class
#include "cScreen.h"

//Including each screen of application
#include "test.h"		//draws a green circly, just using as a test to make sure things work
#include "TestGrid.h"	//draws the entire grid, using it to see if grid setting up correctly

#endif // SCREENS_H