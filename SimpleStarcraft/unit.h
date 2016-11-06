#pragma once

#include <SFML\Graphics.hpp>

class Unit
{
private:
	sf::Vector2f position;
	sf::Vector2f destination;
	sf::Vector2f orig;
	bool moving;

public:
	Unit(float x = 0, float y = 0);

	void move(float x, float y);

	const sf::Vector2f& multiply(const sf::Vector2f& a, float b);

	float Unit::abs(const sf::Vector2f& a);

	void update(double dt);

	const sf::Vector2f& getPosition();
};