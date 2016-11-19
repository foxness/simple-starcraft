#pragma once

#include "entity.h"

class Resource : public Entity
{
protected:
	const int capacity;
	int amountLeft;

	Resource(const Vector& position_, int size_, int capacity_, const sf::Color& color_);

public:
	int getCapacity() const;

	int getAmountLeft() const;

	virtual void update(float dt) override;
};