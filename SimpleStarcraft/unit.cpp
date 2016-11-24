#define _USE_MATH_DEFINES

#include "unit.h"
#include "constants.h"
#include <cmath>
#include <iostream>

Unit::Unit(const Vector& position_, int size_, float maxHealth_, float moveSpeed_, const sf::Color& color_, const EntityType& type_) : Entity(position_, size_, maxHealth_, color_, type_), moveSpeed(moveSpeed_) {}

void Unit::startMovingTo(const Vector& location)
{
	moving = true;
	destination = location;
	moveVector = (destination - position).normalized() * moveSpeed;
}

void Unit::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	const float beakSize = size * BEAKSIZE_COEFFICIENT + BEAKSIZE;
	const float unitAngle = moveVector.getAngle();

	const float beakX = position.getX() + size * cos(unitAngle);
	const float beakY = position.getY() + size * sin(unitAngle);

	sf::Vertex beak[BEAK_VERTICES + 1];
	for (int i = 0; i < BEAK_VERTICES; ++i)
	{
		float angle = unitAngle + (i - 1) * 2 * M_PI / BEAK_VERTICES;
	    beak[i] = sf::Vertex(sf::Vector2f(beakX + beakSize * cos(angle),
			                              beakY + beakSize * sin(angle)), BEAK_COLOR);
	}
	beak[BEAK_VERTICES] = beak[0];

	target.draw(beak, BEAK_VERTICES + 1, sf::LinesStrip);

	Entity::draw(target, states);
}

void Unit::interactWith(Entity& entity)
{
	std::cout << *this << " is interacting with " << entity << std::endl;
	//startMovingTo(entity.getPosition());
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