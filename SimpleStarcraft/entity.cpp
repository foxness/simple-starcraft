#include "entity.h"

Entity::Entity(const Vector& position_, int size_, float health_) : EntityBase(position_), size(size_), health(health_) {}

int Entity::getSize() const
{
	return size;
}

float Entity::getHealth() const
{
	return health;
}
