#pragma once
//======================================================================================
//Header file for bots: initially cBotRandom is defined here, but other bot classes
//can go here too
//
//(c) Patrick Dickinson, University of Lincoln, School of Computer Science, 2020
//======================================================================================

#include "botbase.h"
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
	



	virtual void ChooseNextGridPosition();

private:
	float getAngle();

	std::vector<int> getMovementVector(float angle);
	std::vector<int> rotateOnCollision(std::vector<int> originalMovementVector);
};


