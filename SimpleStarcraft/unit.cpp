#include <SFML\Graphics.hpp>
#include "unit.h"
#include <cmath>

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

float Unit::abs(const sf::Vector2f& a)
{
	return std::sqrt(a.x * a.x + a.y * a.y);
}

void Unit::update(double dt)
{
	if (moving)
	{
		if (abs(destination - position) < 1)
		{
			position = destination;
			moving = false;
		}
		else
		{
			position += multiply((destination - orig), dt);
		}
	}
}

const sf::Vector2f& Unit::getPosition()
{
	return position;
}