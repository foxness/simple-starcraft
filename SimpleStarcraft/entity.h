#pragma once

#include "entitybase.h"

class Entity : public EntityBase
{
protected:
	int size;
	float health;
	const float maxHealth;

	Entity(const Vector& position_, int size_, float maxHealth_);

public:
	virtual void drawSelection(sf::RenderTarget& target) const;

	virtual void drawHealthbar(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

	int getSize() const;

	float getHealth() const;
};