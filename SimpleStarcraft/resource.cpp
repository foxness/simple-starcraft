#include "resource.h"
#include "constants.h"

Resource::Resource(const Vector& position_, int size_, int capacity_, const sf::Color& color_, const std::string& name_) : Entity(position_, size_, RESOURCE_HEALTH, color_, name_), capacity(capacity_) {}

int Resource::getCapacity() const
{
	return capacity;
}

int Resource::getAmountLeft() const
{
	return amountLeft;
}

void Resource::update(float dt) {}