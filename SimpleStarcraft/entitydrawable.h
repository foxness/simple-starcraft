#pragma once

#include "complexdrawable.h"
#include "vector.h"

class EntityDrawable : public ComplexDrawable
{
protected:
	const Vector& position;
	const int& size;
	std::shared_ptr<sf::CircleShape> mainShape;

public:
	EntityDrawable(const Vector& position_, const int& size);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};