#include "entity.h"
#include <SFML/Graphics.hpp>
#include "vector.h"

Entity::Entity(Vector position_, float health_, int size_) : position(position_), health(health_), size(size_) {}

virtual void Entity::draw(sf::RenderWindow& rw) const override
{
	// todo: draw here
}

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