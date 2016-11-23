#define _USE_MATH_DEFINES

#include "entity.h"
#include "constants.h"
#include <cmath>

Entity::Entity(const Vector& position_, int size_, float maxHealth_, const sf::Color& color_, const std::string& name_) : EntityBase(position_), size(size_), health(maxHealth_), maxHealth(maxHealth_), shape(sf::CircleShape(size_)), name(name_)
{
	shape.setFillColor(color_);
	shape.setOrigin(size, size);
}

void Entity::drawSelection(sf::RenderTarget& target) const
{
	float selectionSize = size * SELECTION_SIZE_COEFFICIENT;

	sf::Vertex vertices[SELECTION_SEGMENTS + 1];
	for (int i = 0; i < SELECTION_SEGMENTS; ++i)
	{
		float angle = 2 * M_PI / SELECTION_SEGMENTS * i;
		vertices[i] = sf::Vertex(sf::Vector2f(position.getX() + selectionSize * cos(angle),
			                                  position.getY() + selectionSize * sin(angle)), SELECTION_COLOR);
	}

	vertices[SELECTION_SEGMENTS] = vertices[0];
	target.draw(vertices, SELECTION_SEGMENTS + 1, sf::LinesStrip);
}

void Entity::drawHealthbar(sf::RenderTarget& target, sf::RenderStates states) const
{
	const float dist = size * HEALTHBAR_DIST_COEFFICINENT + HEALTHBAR_DIST;

	sf::RectangleShape bg(sf::Vector2f(HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT));
	bg.setFillColor(HEALTHBAR_BG_COLOR);
	bg.setOutlineThickness(HEALTHBAR_OUTLINE_THICKNESS);
	bg.setOrigin(HEALTHBAR_WIDTH * ORIGIN_COEFFICIENT, HEALTHBAR_HEIGHT * ORIGIN_COEFFICIENT);
	bg.setFillColor(HEALTHBAR_OUTLINE_COLOR);
	bg.setPosition(position.getX(), position.getY() - dist);

	sf::RectangleShape hb(sf::Vector2f(HEALTHBAR_WIDTH * health / maxHealth, HEALTHBAR_HEIGHT));
	hb.setFillColor(HEALTHBAR_COLOR);
	hb.setOrigin(HEALTHBAR_WIDTH * ORIGIN_COEFFICIENT, HEALTHBAR_HEIGHT * ORIGIN_COEFFICIENT);
	hb.setPosition(position.getX(), position.getY() - dist);

	target.draw(bg, states);
	target.draw(hb, states);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	shape.setPosition(position);
	target.draw(shape, states);
}

bool Entity::contains(const Vector& point) const
{
	return (point - position).getLength() <= size;
}

int Entity::getSize() const
{
	return size;
}

float Entity::getHealth() const
{
	return health;
}

const std::string& Entity::getName() const
{
	return name;
}

std::ostream& operator<<(std::ostream& a, const Entity& b)
{
	return a << "[ID " << b.getId() << " - " << b.getName() << "]";
}