#pragma once

#include "resource.h"

class MineralPatch : public Resource
{
public:
	MineralPatch(const Vector& position_);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};