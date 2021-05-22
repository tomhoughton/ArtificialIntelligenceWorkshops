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


