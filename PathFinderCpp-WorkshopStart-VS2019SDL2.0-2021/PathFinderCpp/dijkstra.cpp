#include "bots.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

void cDijkstra::Build(cBotBase& bot)
{
	/*
	bool close[GRIDWIDTH][GRIDHEIGHT]; // Whether or not the location is closed.
	float cost[GRIDWIDTH][GRIDHEIGHT]; // Cost value for each location.
	int linkX[GRIDWIDTH][GRIDHEIGHT]; // Link x coord for each location.
	int linkY[GRIDWIDTH][GRIDHEIGHT]; // Link y coord for each location.
	bool inPath[GRIDWIDTH][GRIDHEIGHT]; // Whether or not a location is in.
	*/

	// Set all data arrays to default value.
	for (int x = 0; x <= GRIDWIDTH - 1; x++) {
		for (int y = 0; y <= GRIDHEIGHT - 1; y++) {
			closed[x][y] = false;
			cost[x][y] = 1000000.0f;
			linkX[x][y] = -1;
			linkY[x][y] = -1;
			inPath[x][y] = false;
		}
	}

	// Set the cost of the bots position to 0;
	cost[bot.PositionX()][bot.PositionY()] = 0;

	// Create the while loop:
	while (closed[gTarget.PositionX()][gTarget.PositionY()] != true)
	{
		// Find the position with the lowest cost:
		std::vector<int> lowestCostCoordinates = lowestCostPosition(cost); // Find the lowest Cost.

		// Set this location as closed:
		closed[lowestCostCoordinates[0]][lowestCostCoordinates[1]] = true;

		// Calculate a new cost for the 8 neighboring tilesL:
		/*
		// Up
		int upX = lowestCostCoordinates[0];
		int upY = lowestCostCoordinates[1] + 1;

		// Check if the position is valid
		if (isPositionValid(upX, upY)) {

			int newCost = cost[lowestCostCoordinates[0]][lowestCostCoordinates[1]] + 1;

			if (newCost < cost[upX][upY]) {
				cost[upX][upY] = newCost;
				linkX[upX][upY] = lowestCostCoordinates[0];
				linkY[upX][upY] = lowestCostCoordinates[1];
			}
		}


		// Down
		int downX = lowestCostCoordinates[0];
		int downY = lowestCostCoordinates[1] - 1;

		// Check if the position is valid
		if (isPositionValid(downX, downY)) {

			int newCost = cost[lowestCostCoordinates[0]][lowestCostCoordinates[1]] + 1;

			if (newCost < cost[downX][downY]) {
				cost[downX][downY] = newCost;
				linkX[downX][downY] = lowestCostCoordinates[0];
				linkY[downX][downY] = lowestCostCoordinates[1];
			}
		}

		// Left
		int leftX = lowestCostCoordinates[0] - 1;
		int leftY = lowestCostCoordinates[1];

		// Check if the position is valid
		if (isPositionValid(downX, downY)) {

			int newCost = cost[lowestCostCoordinates[0] - 1][lowestCostCoordinates[1]] + 1;

			if (newCost < cost[leftX][leftY]) {
				cost[leftX][leftY] = newCost;
				linkX[leftX][leftY] = lowestCostCoordinates[0];
				linkY[leftX][leftY] = lowestCostCoordinates[1];
			}
		}
		

		// Right 
		int rightX = lowestCostCoordinates[0] + 1;
		int rightY = lowestCostCoordinates[1];

		// Check if the position is valid
		if (isPositionValid(rightX, rightY)) {

			int newCost = cost[lowestCostCoordinates[0] + 1][lowestCostCoordinates[1]] + 1;

			if (newCost < cost[rightX][rightY]) {
				cost[rightX][rightY] = newCost;

				linkX[rightX][rightY] = lowestCostCoordinates[0];
				linkY[rightX][rightY] = lowestCostCoordinates[1];
			}
		}

		// Up Left
		int upLeftX = lowestCostCoordinates[0] - 1;
		int upleftY = lowestCostCoordinates[1] + 1;

		// Check if the position is valid
		if (isPositionValid(upLeftX, upleftY)) {

			int newCost = cost[lowestCostCoordinates[0] - 1][lowestCostCoordinates[1] + 1] + 1.4;

			if (newCost < cost[upLeftX][upleftY]) {
				cost[upLeftX][upleftY] = newCost;

				linkX[upLeftX][upleftY] = lowestCostCoordinates[0];
				linkY[upLeftX][upleftY] = lowestCostCoordinates[1];
			}
		}

		// Up Right
		int upRightX = lowestCostCoordinates[0] + 1;
		int upRightY = lowestCostCoordinates[1] + 1;

		// Check if the position is valid
		if (isPositionValid(upRightX, upRightY)) {

			int newCost = cost[lowestCostCoordinates[0] + 1][lowestCostCoordinates[1] + 1] + 1.4;

			if (newCost < cost[upRightX][upRightY]) {
				cost[upRightX][upRightY] = newCost;

				linkX[upRightX][upRightY] = lowestCostCoordinates[0];
				linkY[upRightX][upRightY] = lowestCostCoordinates[1];
			}
		}

		// Down Left
		int downLeftX = lowestCostCoordinates[0] - 1;
		int downleftY = lowestCostCoordinates[1] - 1;

		// Check if the position is valid
		if (isPositionValid(downLeftX, downleftY)) {

			int newCost = cost[lowestCostCoordinates[0] - 1][lowestCostCoordinates[1] - 1] + 1.4;

			if (newCost < cost[downLeftX][downleftY]) {
				cost[downLeftX][downleftY] = newCost;

				linkX[downLeftX][downleftY] = lowestCostCoordinates[0];
				linkY[downLeftX][downleftY] = lowestCostCoordinates[1];
			}
		}
		
		// Down Right
		int downRightX = lowestCostCoordinates[0] + 1;
		int downRightY = lowestCostCoordinates[1] - 1;

		// Check if the position is valid
		if (isPositionValid(downRightX, downRightY)) {

			int newCost = cost[lowestCostCoordinates[0] + 1][lowestCostCoordinates[1] - 1] + 1.4;

			if (newCost < cost[downRightX][downRightY]) {
				cost[downRightX][downRightY] = newCost;

				linkX[downRightX][downRightY] = lowestCostCoordinates[0];
				linkY[downRightX][downRightY] = lowestCostCoordinates[1];
			}
		}
		*/
	
		setDataArrays(lowestCostCoordinates, "up", 1);
		setDataArrays(lowestCostCoordinates, "down", 1);
		setDataArrays(lowestCostCoordinates, "left", 1);
		setDataArrays(lowestCostCoordinates, "right", 1);
		setDataArrays(lowestCostCoordinates, "upRight", 1.4);
		setDataArrays(lowestCostCoordinates, "upLeft", 1.4);
		setDataArrays(lowestCostCoordinates, "downRight", 1.4);
		setDataArrays(lowestCostCoordinates, "downLeft", 1.4);
	}			

	// Trace through the links array:
	bool done = false; // set to true when we are back at the bot position.
	int nextClosedX = gTarget.PositionX(); // Start of the path.
	int nextClosedY = gTarget.PositionY(); // Start of path.

	while (!done)
	{
		inPath[nextClosedX][nextClosedY] = true;
		int tmpX = nextClosedX;
		int tmpY = nextClosedY;
		while (!done)
		{
			inPath[nextClosedX][nextClosedY] = true;
			int tmpX = nextClosedX;
			int tmpY = nextClosedY;
			nextClosedX = linkX[tmpX][tmpY];
			nextClosedY = linkY[tmpX][tmpY];
			if ((nextClosedX == bot.PositionX()) && (nextClosedY == bot.PositionY())) done = true;

		}
	}

	completed = true;

	cDijkstra gDijkstra;
}

void cDijkstra::setDataArrays(std::vector<int> position, std::string direction, float costIncrement)
{
	int X = getXAxis(position[0], direction);
	int Y = getYAxis(position[1], direction);

	if (isPositionValid(X, Y))
	{
		int newCost = cost[position[0]][position[0]] + costIncrement;

		if (newCost < cost[X][Y])
		{
			cost[X][Y] = newCost;

			linkX[X][Y] = position[0];
			linkY[X][Y] = position[1];
		}
	}
}

int cDijkstra::getXAxis(int positionX, std::string direction)
{
	if (direction == "up")
	{
		return positionX;
	}
	else if (direction == "down")
	{
		return positionX;
	}
	else if (direction == "left")
	{
		return positionX - 1;
	}
	else if (direction == "right")
	{
		return positionX + 1;
	}
	else if (direction == "upRight")
	{
		return positionX + 1;
	}
	else if (direction == "upLeft")
	{
		return positionX - 1;
	}
	else if (direction == "downRight")
	{
		return positionX + 1;
	}
	else if (direction == "downLeft")
	{
		return positionX - 1;
	}
}

int cDijkstra::getYAxis(int positionY, std::string direction)
{
	if (direction == "up")
	{
		return positionY + 1;
	}
	else if (direction == "down")
	{
		return positionY - 1;
	}
	else if (direction == "left")
	{
		return positionY;
	}
	else if (direction == "right")
	{
		return positionY;
	}
	else if (direction == "upRight")
	{
		return positionY + 1;
	}
	else if (direction == "upLeft")
	{
		return positionY - 1;
	}
	else if (direction == "downRight")
	{
		return positionY - 1;
	}
	else if (direction == "downLeft")
	{
		return positionY - 1;
	}
}

bool cDijkstra::isPositionValid(int x, int y)
{
	if (gLevel.isValid(x, y) && (closed[x][y] == false)) {
		return true;
	}
	return false; 
}

std::vector<int> cDijkstra::lowestCostPosition(float cost[GRIDWIDTH][GRIDHEIGHT])
{
	std::vector<int> lowestCostCoords; // Stores the coordinates of the lowest cost and the cost itself.
	float lowestCost = 1000000.0f; // Stores the lowest cost for comparison.

	// make sure that the position isn't block and isn't closed.
	for (int x = 0; x <= GRIDWIDTH - 1; x++) {
		for (int y = 0; y <= GRIDHEIGHT - 1; y++) {
			if (gLevel.isValid(x, y) && closed[x][y] != true) {
				if (cost[x][y] < lowestCost) {
					lowestCost = cost[x][y];
					lowestCostCoords[0] = x;
					lowestCostCoords[1] = y;
				}
			}
		}
	}

	return lowestCostCoords;
}

void cDijkstra::ChooseNextGridPosition() {
	std::cout << "Hello" << std::endl;
}