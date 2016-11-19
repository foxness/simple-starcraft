#define _USE_MATH_DEFINES

#include "unit.h"
#include <cmath>
#include <iostream>

Unit::Unit(const Vector& position_, int size_, float maxHealth_, float moveSpeed_, const sf::Color& color_) : Entity(position_, size_, maxHealth_, color_), moveSpeed(moveSpeed_) {}

void Unit::startMovingTo(const Vector& location)
{
	moving = true;
	destination = location;
	moveVector = (destination - position).normalized() * moveSpeed;
}

void Unit::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const float beakSize = size * 1.5f - 3;
	const int vertices = 3;
	const float unitAngle = moveVector.getAngle();

	const float beakX = position.getX() + size * cos(unitAngle);
	const float beakY = position.getY() + size * sin(unitAngle);

	sf::Vertex beak[vertices + 1];
	for (int i = 0; i < vertices; ++i)
	{
		float angle = unitAngle + (i - 1) * 2 * M_PI / 3;
	    beak[i] = sf::Vertex(sf::Vector2f(beakX + beakSize * cos(angle),
			                              beakY + beakSize * sin(angle)), sf::Color::White);
	}
	beak[vertices] = beak[0];

	target.draw(beak, vertices + 1, sf::LinesStrip);

	Entity::draw(target, states);
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