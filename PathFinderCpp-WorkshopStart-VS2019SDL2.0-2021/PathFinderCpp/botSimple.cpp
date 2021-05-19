#include "bots.h"
#include "stdlib.h"
#include <iostream>

void cBotSimple::ChooseNextGridPosition()
{
	int x = PositionX(); // Store current x location.
	int y = PositionY(); // Store current y location.

	int newX = 0; // Store new 'x' location.
	int newY = 0; // Store new 'y' location.

	newX = PositionX() + 1; // Set 'x' location.
	newY = PositionY(); // Set 'y' location.

	// Check if the new position if valid:
	if (gLevel.isValid(newX, newY)) 
	{
		std::cout << "VALID" << std::endl;
		SetNext(newX, newY, gLevel); // Change the position.
	}

}