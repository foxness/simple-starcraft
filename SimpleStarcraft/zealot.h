#pragma once

#include "unit.h"

class Zealot : public Unit
{
public:
	Zealot(const Vector& position_);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};