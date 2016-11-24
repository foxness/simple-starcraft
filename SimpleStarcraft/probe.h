#pragma once

#include "unit.h"
#include "resource.h"
#include "nexus.h"
#include <memory>

enum class HarvestingStage
{
	MovingToResource, Mining, Returning
};

class Probe : public Unit
{
protected:
	bool carryingResources = false;
	bool harvesting = false;
	HarvestingStage hs = HarvestingStage::MovingToResource;
	std::shared_ptr<Resource> resource; // the resource to be harvested
	std::shared_ptr<Nexus> nexus; // the nexus to bring the harvest to
	float harvestTimeCounter = 0;

	mutable sf::RectangleShape res;

public:
	Probe(const Vector& position_);

	virtual void update(float dt) override;

	void harvest(const std::shared_ptr<Resource>& resource_, const std::shared_ptr<Nexus>& nexus_);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

	virtual void move(const Vector& location) override;
};