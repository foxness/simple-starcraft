#include "structure.h"

Structure::Structure(const Vector& position_, int size_, float maxHealth_, const sf::Color& color_, const EntityType& type_) : Entity(position_, size_, maxHealth_, color_, type_) {}

void Structure::update(float dt)
{
	// structures dont have anything to update yet...
}
