#define _USE_MATH_DEFINES

#include "unit.h"
#include <cmath>
#include "vector.h"
#include <iostream>

Unit::Unit(float x, float y)
{
	position = Vector(x, y);
	moving = false;
	speed = 120;
}

void Unit::startMovingTo(float x, float y)
{
	moving = true;
	destination = Vector(x, y);
	movingVector = (destination - position).normalized() * speed;
}

void Unit::update(float dt)
{
	if (moving)
	{
		std::cout << (destination - position).getLength() << std::endl;
		if ((destination - position).getLength() < 1)
		{
			position = destination;
			moving = false;
		}
		else
		{
			position = position + movingVector * dt;
		}
	}
}

const Vector& Unit::getPosition()
{
	return position;
}