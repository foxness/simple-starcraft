#include <SFML\Graphics.hpp>
#include "unit.h"

Unit::Unit(float x, float y)
{
	position = sf::Vector2f(x, y);
}

void Unit::move(float x, float y)
{
	moving = true;
	destination = sf::Vector2f(x, y);
	orig = position;
}

const sf::Vector2f& Unit::multiply(const sf::Vector2f& a, float b)
{
	return sf::Vector2f(a.x * b, a.y * b);
}

void Unit::update(double dt)
{
	if (moving)
		position += multiply((destination - orig), dt);
}

const sf::Vector2f& Unit::getPosition()
{
	return position;
}