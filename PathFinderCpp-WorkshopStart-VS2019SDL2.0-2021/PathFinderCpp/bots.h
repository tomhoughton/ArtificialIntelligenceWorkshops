#pragma once
//======================================================================================
//Header file for bots: initially cBotRandom is defined here, but other bot classes
//can go here too
//
//(c) Patrick Dickinson, University of Lincoln, School of Computer Science, 2020
//======================================================================================

#include "botbase.h"
#include <iostream>
#include <vector>

class cBotRandom : public cBotBase
{
	virtual void ChooseNextGridPosition();
};

class cBotSimple : public cBotBase
{
	virtual void ChooseNextGridPosition();
};

class cBotSimple2 : public cBotBase
{
public: 
	
	bool isNearWall;
	bool wallIsRight;
	bool wallIsUp;
	bool handleCorner;

	int prevX;
	int prevY;

	std::vector<int> cornerLocation;

	cBotSimple2();

	virtual void ChooseNextGridPosition();
	std::string checkWallLocation();

private:
	float getAngle();

	std::vector<int> getMovementVector(float angle);
	//std::vector<int> escapeCorner();
	std::vector<int> rotateOnCollision(std::vector<int> originalMovementVector);
	//std::vector<int> checkForCollision(std::vector<int> movementVector, int newX, int newY);
	bool checkForCorner();

};

class cDijkstra : public cBotBase
{
public:
	bool closed[GRIDWIDTH][GRIDHEIGHT]; // Whether or not the location is closed.
	float cost[GRIDWIDTH][GRIDHEIGHT]; // Cost value for each location.
	int linkX[GRIDWIDTH][GRIDHEIGHT]; // Link x coord for each location.
	int linkY[GRIDWIDTH][GRIDHEIGHT]; // Link y coord for each location.
	bool inPath[GRIDWIDTH][GRIDHEIGHT]; // Whether or not a location is in.

	bool completed;

	cDijkstra() {
		completed = false;
	};
	
	virtual void Build(cBotBase& bot);

	virtual void ChooseNextGridPosition();
	
private:
	std::vector<int> lowestCostPosition(float cost[GRIDWIDTH][GRIDHEIGHT]);
	bool isPositionValid(int x, int y);
	void setDataArrays(std::vector<int> position, std::string direction, float costIncrement);
	int getXAxis(int positionX, std::string direction);
	int getYAxis(int positionY, std::string direction); 
};

extern cDijkstra gDijkstra;

