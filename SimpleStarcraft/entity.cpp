#define _USE_MATH_DEFINES

#include "entity.h"
#include <cmath>

Entity::Entity(const Vector& position_, int size_, float health_) : EntityBase(position_), size(size_), health(health_) {}

void Entity::drawSelection(sf::RenderTarget& target) const
{
	const int segments = 36;
	float selectionSize = size * 1.3f;

	sf::Vertex vertices[segments + 1];
	for (int i = 0; i < segments; ++i)
	{
		float angle = 2 * M_PI / segments * i;
		vertices[i] = sf::Vertex(sf::Vector2f(position.getX() + selectionSize * cos(angle),
			                                  position.getY() + selectionSize * sin(angle)), sf::Color::Green);
	}

	vertices[segments] = vertices[0];
	target.draw(vertices, segments + 1, sf::LinesStrip);
}

int Entity::getSize() const
{
	return size;
}

float Entity::getHealth() const
{
	return health;
}
