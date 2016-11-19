#pragma once

#include "unit.h"

class Probe : public Unit
{
protected:
	bool carryingResources = false;
	mutable sf::RectangleShape res;

public:
	Probe(const Vector& position_);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};