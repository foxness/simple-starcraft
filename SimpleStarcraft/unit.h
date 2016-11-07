#pragma once

#include "vector.h"

class Unit
{
private:
	Vector position;
	Vector destination;
	Vector movingVector;
	float speed;
	bool moving;

public:
	Unit(float x = 0, float y = 0);

	void startMovingTo(float x, float y);

	void update(float dt);

	const Vector& getPosition();
};