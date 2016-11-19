#include "probe.h"

Probe::Probe(const Vector& position_) : Unit(position_, 7, 10, 120) {}

void Probe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape s(size);
	s.setPosition(position);
	s.setOrigin(Vector(size, size));
	s.setFillColor(sf::Color(120, 80, 170));
	
	target.draw(s, states);

	if (carryingResources)
	{
		float angle = moveVector.getAngle();
		sf::RectangleShape res(sf::Vector2f(4, 4));
		res.setOrigin(2, 2);
		res.setFillColor(sf::Color::Cyan);
		res.setPosition(position + Vector(size * cos(angle), size * sin(angle)));

		target.draw(res, states);
	}
}
