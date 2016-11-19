#pragma once

#include "structure.h"

class Nexus : public Structure
{
public:
	Nexus(const Vector& position_);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};