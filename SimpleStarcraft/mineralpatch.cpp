#include "mineralpatch.h"

MineralPatch::MineralPatch(const Vector& position_) : Resource(position_, 16, 1000) {}

void MineralPatch::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape s(size);
	s.setPosition(position);
	s.setOrigin(Vector(size, size));
	s.setFillColor(sf::Color::Cyan);
	target.draw(s, states);
}
