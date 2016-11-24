#include "probe.h"
#include "constants.h"

Probe::Probe(const Vector& position_) : Unit(position_, PROBE_SIZE, PROBE_MAXHEALTH, PROBE_MOVESPEED, PROBE_COLOR, PROBE_TYPE)
{
	res = sf::RectangleShape(sf::Vector2f(PROBE_CARRY_SIZE, PROBE_CARRY_SIZE));
	res.setOrigin(PROBE_CARRY_SIZE * ORIGIN_COEFFICIENT, PROBE_CARRY_SIZE * ORIGIN_COEFFICIENT);
	res.setFillColor(MINERALPATCH_COLOR);
}

void Probe::update(float dt)
{
	if (harvesting)
	{
		switch (hs)
		{
		case HarvestingStage::MovingToResource:

			if ((destination - position).getLength() < 1)
			{
				position = destination;
				moving = false;
				hs = HarvestingStage::Mining;
			}
			else
			{
				position += moveVector * dt;
			}

			break;

		case HarvestingStage::Mining:

			if (!carryingResources && harvestTimeCounter < HARVEST_TIME)
			{
				harvestTimeCounter += dt;
			}
			else
			{
				hs = HarvestingStage::Returning;
				carryingResources = true;
				harvestTimeCounter = 0;

				moving = true;
				destination = nexus->getPosition();
				moveVector = (destination - position).normalized() * moveSpeed;
			}

			break;

		case HarvestingStage::Returning:

			if ((destination - position).getLength() < 1)
			{
				hs = HarvestingStage::MovingToResource;
				carryingResources = false;

				destination = resource->getPosition();
				moveVector = (destination - position).normalized() * moveSpeed;
			}
			else
			{
				position += moveVector * dt;
			}

			break;
		}
	}
	else if (moving)
	{
		if ((destination - position).getLength() < 1)
		{
			position = destination;
			moving = false;
		}
		else
		{
			position += moveVector * dt;
		}
	}
}

void Probe::harvest(const std::shared_ptr<Resource>& resource_, const std::shared_ptr<Nexus>& nexus_)
{
	hs = HarvestingStage::MovingToResource;
	resource = resource_;
	nexus = nexus_;
	harvestTimeCounter = 0;
	harvesting = true;
	moving = true;
	destination = resource->getPosition();
	moveVector = (destination - position).normalized() * moveSpeed;
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

void Probe::move(const Vector& location)
{
	harvesting = false;
	Unit::move(location);
}
