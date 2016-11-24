#pragma once

#include "zealot.h"
#include "rectangle.h"
#include "nexus.h"
#include "mineralpatch.h"
#include "probe.h"
#include "updatable.h"
#include <memory>
#include <vector>

class EntityController : public Updatable
{
protected:
	std::vector<std::shared_ptr<Unit>>& units;
	std::vector<std::shared_ptr<Structure>>& structures;
	std::vector<std::shared_ptr<Resource>>& resources;

	std::vector<std::shared_ptr<Entity>>& selectedEntities;

	std::shared_ptr<Nexus> getClosestTo(const std::shared_ptr<MineralPatch>& mp);

public:
	EntityController(std::vector<std::shared_ptr<Unit>>& units_,
		                  std::vector<std::shared_ptr<Structure>>& structures_,
		                  std::vector<std::shared_ptr<Resource>>& resources_,
		                  std::vector<std::shared_ptr<Entity>>& selectedEntities_);

	void action(const Vector& point);

	std::shared_ptr<Entity> getEntityAt(const Vector& point);

	virtual void update(float dt) override;
};