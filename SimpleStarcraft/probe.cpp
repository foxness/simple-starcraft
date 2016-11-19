#include "probe.h"

Probe::Probe(const Vector& position_) : Unit(position_, 7, 10, 120, sf::Color(120, 80, 170))
{
	res = sf::RectangleShape(sf::Vector2f(4, 4));
	res.setOrigin(2, 2);
	res.setFillColor(sf::Color::Cyan);
}

void Probe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Unit::draw(target, states);

	if (carryingResources)
	{
		float angle = moveVector.getAngle();
		res.setPosition(position + Vector(size * cos(angle), size * sin(angle)));
		target.draw(res, states);
	}
}
