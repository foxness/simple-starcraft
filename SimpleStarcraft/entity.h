#pragma once

#include "entitybase.h"

class Entity : public EntityBase
{
protected:
	int size;
	float health;
	const float maxHealth;
	mutable sf::CircleShape shape;

	Entity(const Vector& position_, int size_, float maxHealth_, const sf::Color& color_);

public:
	virtual void drawSelection(sf::RenderTarget& target) const;

	virtual void drawHealthbar(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

	bool contains(const Vector& point) const;

	int getSize() const;

	float getHealth() const;
};