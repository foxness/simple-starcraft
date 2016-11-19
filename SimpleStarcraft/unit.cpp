#define _USE_MATH_DEFINES

#include "unit.h"
#include <cmath>
#include <iostream>

Unit::Unit(const Vector& position_, int size_, float health_, float moveSpeed_) : Entity(position_, size_, health_), moveSpeed(moveSpeed_), moving(false) {}

void Unit::startMovingTo(const Vector& location)
{
	moving = true;
	destination = location;
	moveVector = (destination - position).normalized() * moveSpeed;
}

void Unit::update(float dt)
{
	if (moving)
	{
		if ((destination - position).getLength() < 1)
		{
			position = destination;
			moving = false;
		}
		else
		{
			position += moveVector * dt;
		}
	}
}

float Unit::getMovespeed() const
{
	return moveSpeed;
}

bool Unit::isMoving() const
{
	return moving;
}