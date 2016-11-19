#pragma once

#include "entitybase.h"

class Entity : public EntityBase
{
protected:
	int size;
	float health;

	Entity(const Vector& position_, int size_, float health_);

public:
	virtual void drawSelection(sf::RenderTarget& target) const;

	int getSize() const;

	float getHealth() const;
};