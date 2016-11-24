#include "entitycontroller.h"

EntityController::EntityController(std::vector<std::shared_ptr<Unit>>& units_, std::vector<std::shared_ptr<Structure>>& structures_, std::vector<std::shared_ptr<Resource>>& resources_, std::vector<std::shared_ptr<Entity>>& selectedEntities_)
	: units(units_), structures(structures_), resources(resources_), selectedEntities(selectedEntities_)
{
}

void EntityController::action(const Vector& point)
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

	for (const auto& selected : selectedEntities)
	{
		auto unit = std::dynamic_pointer_cast<Unit>(selected);
		if (unit)
		{
			if (target && unit != target)
				unit->interactWith(*target);
			else
				unit->startMovingTo(point);
		}
	}
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
