#include "entitycontroller.h"
#include <limits>

EntityController::EntityController(std::vector<std::shared_ptr<Unit>>& units_, std::vector<std::shared_ptr<Structure>>& structures_, std::vector<std::shared_ptr<Resource>>& resources_, std::vector<std::shared_ptr<Entity>>& selectedEntities_)
	: units(units_), structures(structures_), resources(resources_), selectedEntities(selectedEntities_)
{
}

void EntityController::action(const Vector& point)
{
	std::shared_ptr<Entity> target = getEntityAt(point);

	for (const auto& selected : selectedEntities)
	{
		switch (selected->getType())
		{
			case EntityType::Probe:
			{
				auto probe = std::static_pointer_cast<Probe>(selected);
				if (!target || probe == target)
				{
					probe->move(point);
				}
				else if (target->getType() == EntityType::MineralPatch)
				{
					auto mp = std::static_pointer_cast<MineralPatch>(target);
					probe->harvest(mp, getClosestTo(mp));
				}
				else
				{
					probe->move(target->getPosition());
				}

				break;
			}
			case EntityType::Zealot:
			{
				auto zealot = std::static_pointer_cast<Zealot>(selected);
				if (!target || zealot == target)
				{
					zealot->move(point);
				}
				else
				{
					zealot->move(target->getPosition());
				}

				break;
			}
		}
	}
}

std::shared_ptr<Entity> EntityController::getEntityAt(const Vector& point)
{
	std::shared_ptr<Entity> target;
	for (const auto& unit : units)
		if (unit->contains(point))
		{
			target = unit;
			break;
		}
	if (!target)
	{
		for (const auto& structure : structures)
			if (structure->contains(point))
			{
				target = structure;
				break;
			}
	}

	if (!target)
	{
		for (const auto& resource : resources)
			if (resource->contains(point))
			{
				target = resource;
				break;
			}
	}

	return target;
}

std::shared_ptr<Nexus> EntityController::getClosestTo(const std::shared_ptr<MineralPatch>& mp)
{
	std::shared_ptr<Nexus> result;
	float minDist = std::numeric_limits<float>::max();
	for (const auto& nex : structures)
		if (nex->getType() == EntityType::Nexus)
		{
			float dist = (mp->getPosition() - nex->getPosition()).getLength();
			if (dist < minDist)
			{
				minDist = dist;
				result = std::static_pointer_cast<Nexus>(nex);
			}
		}
	return result;
}

void EntityController::update(float dt)
{
	for (auto& unit : units)
		unit->update(dt);

	//for (auto& structure : structures)
	//	structure->update(dt);

	//for (auto& resource : resources)
	//	resource->update(dt);
}
