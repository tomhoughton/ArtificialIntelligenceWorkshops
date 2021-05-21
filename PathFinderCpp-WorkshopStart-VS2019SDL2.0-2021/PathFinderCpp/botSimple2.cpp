#include "bots.h"
#include "stdlib.h"
#include <iostream>
#include <vector>


void cBotSimple2::ChooseNextGridPosition() 
{
	// Get the angle:
	float angle = getAngle();

	// Create movement vector:
	std::vector<int> movementVector = getMovementVector(angle);

	// When it hits a wall or map edge then pick a new direction based on player location

	// Check direction with glevel.isValid();

	// Move:
	int x = PositionX(); // Store current x location.
	int y = PositionY(); // Store current y location.

	int newX = PositionX() + movementVector[0]; // Store new 'x' location.
	int newY = PositionY() + movementVector[1]; // Store new 'y' location.

	if (gLevel.isValid(newX, newY))
	{
		SetNext(newX, newY, gLevel);
	}
	else
	{
		
	}
}

float cBotSimple2::getAngle() 
{	
	// North angle: 

	float pi = 3.14159265359;

	// Get bot and player Locations.
	float botLocation[2] = { static_cast<float>(PositionX()), static_cast<float>(PositionY()) };
	float playerLocation[2] = { static_cast<float>(gTarget.PositionX()), static_cast<float>(gTarget.PositionY()) };
	

	// Work out angle: 
	float radians = atan2(playerLocation[1] - botLocation[1], playerLocation[0] - botLocation[0]);

	float angle = radians * 180 / pi;

	return angle;
}

std::vector<int> cBotSimple2::rotateOnCollision(std::vector<int> originalMovementVector)
{
	std::vector<int> rtn = { 0, 0 };

	// Get half way 'y' point:
	if (PositionY() < gTarget.PositionY())
	{
		rtn[0] = originalMovementVector[0];
		rtn[1] = originalMovementVector[1] + 1;
	}
	else if (PositionY() > gTarget.PositionY())
	{
		rtn[0] = originalMovementVector[0];
		rtn[1] = originalMovementVector[1] - 1;
	}

	return rtn;
}

std::vector<int> cBotSimple2::getMovementVector(float angle)
{
	std::vector<int> movementVector = { 0, 0 };

	if (angle < 0 && angle > -90) {
		// Move diagonally northEast.
		movementVector[0] = 1;
		movementVector[1] = -1;

	}
	else if (angle < -90 && angle > -179) {
		// Move diagonally northWest.
		movementVector[0] = -1;
		movementVector[1] = -1;
	}
	else if (angle < 180 && angle > 90) {
		// Move diagonally southWest.
		movementVector[0] = -1;
		movementVector[1] = 1;
	}
	else if (angle > 0 && angle < 90) {
		// Move diagonally southEast.
		movementVector[0] = 1;
		movementVector[1] = 1;
	}
	else if (angle == 0) {
		// Move Right:
		movementVector[0] = 1;
		movementVector[1] = 0;
	}
	else if (angle == -90) {
		// Move Up:
		movementVector[0] = 0;
		movementVector[1] = -1;
	}
	else if (angle == 180) {
		// Move Left:
		movementVector[0] = -1;
		movementVector[1] = 0;
	}
	else if (angle == 90) {
		// Move down:
		movementVector[0] = 0;
		movementVector[1] = 1;
	}

	return movementVector;
}