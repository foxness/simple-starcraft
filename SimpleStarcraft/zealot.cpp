#include "zealot.h"
#include <memory>
#include "vector.h"

Zealot::Zealot(const Vector& position_) : Unit(position_, 10, 10, 150)
{
	drawable = std::make_unique<sf::CircleShape>(10);
}