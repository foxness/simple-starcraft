#define _USE_MATH_DEFINES

#include "entity.h"
#include <cmath>

Entity::Entity(const Vector& position_, int size_, float maxHealth_) : EntityBase(position_), size(size_), health(maxHealth_), maxHealth(maxHealth_) {}

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

void Entity::drawHealthbar(sf::RenderTarget& target, sf::RenderStates states) const
{
	const float width = 35;
	const float height = 6;
	const float dist = size * 1.3f + 9;

	sf::RectangleShape bg(sf::Vector2f(width, height));
	bg.setFillColor(sf::Color::Transparent);
	bg.setOutlineThickness(1);
	bg.setOrigin(width / 2, height / 2);
	bg.setPosition(position.getX(), position.getY() - dist);

	sf::RectangleShape hb(sf::Vector2f(width * health / maxHealth, height));
	hb.setFillColor(sf::Color::Green);
	hb.setOrigin(width / 2, height / 2);
	hb.setPosition(position.getX(), position.getY() - dist);

	target.draw(hb, states);
	target.draw(bg, states);
}

int Entity::getSize() const
{
	return size;
}

float Entity::getHealth() const
{
	return health;
}
