#include "entitydrawable.h"

EntityDrawable::EntityDrawable(const Vector& position_, const int& size_) : position(position_), size(size_)
{
	mainShape = std::make_shared<sf::CircleShape>(size);
	shapes.push_back(mainShape);
}

void EntityDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	mainShape->setPosition(position.getX(), position.getY());

	ComplexDrawable::draw(target, states);
}
