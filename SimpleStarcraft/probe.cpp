#include "probe.h"
#include "constants.h"

Probe::Probe(const Vector& position_) : Unit(position_, PROBE_SIZE, PROBE_MAXHEALTH, PROBE_MOVESPEED, PROBE_COLOR, PROBE_TYPE)
{
	res = sf::RectangleShape(sf::Vector2f(PROBE_CARRY_SIZE, PROBE_CARRY_SIZE));
	res.setOrigin(PROBE_CARRY_SIZE * ORIGIN_COEFFICIENT, PROBE_CARRY_SIZE * ORIGIN_COEFFICIENT);
	res.setFillColor(MINERALPATCH_COLOR);
}

void Probe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Unit::draw(target, states);

	if (carryingResources)
	{
		float angle = moveVector.getAngle();
		res.setPosition(position + Vector(size * cos(angle), size * sin(angle)));
		target.draw(res, states);
	}
}
