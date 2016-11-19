#include "nexus.h"

Nexus::Nexus(const Vector& position_) : Structure(position_, 48, 500) {}

void Nexus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape s(size);
	s.setFillColor(sf::Color::Yellow);
	s.setPosition(position);
	s.setOrigin(Vector(size, size));
	target.draw(s, states);
}
