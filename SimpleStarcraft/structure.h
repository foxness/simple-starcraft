#pragma once

#include "entity.h"

class Structure : public Entity
{
protected:
	Structure(const Vector& position_, int size_, float maxHealth_, const sf::Color& color_, const EntityType& type_);

public:
	virtual void update(float dt) override;
};