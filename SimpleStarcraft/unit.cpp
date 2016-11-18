#define _USE_MATH_DEFINES

#include "unit.h"
#include <cmath>
#include "vector.h"
#include <iostream>
#include "entity.h"

Unit::Unit(const Vector& position_, float health_, int size_, float moveSpeed_) : Entity(position_, health_, size_), moveSpeed(moveSpeed_), moving(false) {}

void Unit::startMovingTo(const Vector& location)
{
	moving = true;
	destination = location;
	moveVector = (destination - position).normalized() * moveSpeed;
}

void Unit::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*drawable, states.transform.translate(position.getX(), position.getY()));
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