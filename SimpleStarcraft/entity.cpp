#include "entity.h"
#include <SFML/Graphics.hpp>
#include "vector.h"
#include <iostream>

Entity::Entity(Vector position_, int size_) : position(position_), size(size_) {}

const Vector& Entity::getPosition() const
{
	return position;
}

int Entity::getSize() const
{
	return size;
}