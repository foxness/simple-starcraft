#pragma once

#include "entitybase.h"

class Entity : public EntityBase
{
protected:
	int size;
	float health;

	Entity(const Vector& position_, int size_, float health_);

public:
	int getSize() const;

	float getHealth() const;
};