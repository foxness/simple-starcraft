#include "entity.h"
#include <SFML/Graphics.hpp>
#include "vector.h"
#include <iostream>

Entity::Entity(Vector position_, float health_, int size_) : position(position_), health(health_), size(size_) {}

const Vector& Entity::getPosition() const
{
	return position;
}

float Entity::getHealth() const
{
	return health;
}

int Entity::getSize() const
{
	return size;
}