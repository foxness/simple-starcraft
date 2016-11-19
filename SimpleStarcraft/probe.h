#pragma once

#include "unit.h"

class Probe : public Unit
{
protected:
	bool carryingResources = false;

public:
	Probe(const Vector& position_);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};