#include "zealot.h"
#include "vector.h"

Zealot::Zealot(const Vector& position_) : Unit(position_, 10, 10, 150) {}

void Zealot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape s(size);
	s.setPosition(position);
	target.draw(s);
}
