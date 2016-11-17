#include "entity.h"
#include <SFML/Graphics.hpp>
#include "vector.h"
#include <iostream>

Entity::Entity(Vector position_, float health_, int size_) : position(position_), health(health_), size(size_) {}

void Entity::draw(sf::RenderWindow& rw) const
{
	sf::CircleShape c(size);
	c.setFillColor(sf::Color::Blue);
	c.setPosition(position.getX(), position.getY());
	rw.draw(c);
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