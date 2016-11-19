#pragma once

#include "entity.h"

class Unit : public Entity
{
protected:
	Vector destination;
	Vector moveVector;
	float moveSpeed;
	bool moving = false;

	Unit(const Vector& position_, int size_, float maxHealth_, float moveSpeed_);

public:
    virtual void update(float dt) override;
	
	virtual void startMovingTo(const Vector& location);
	
	float getMovespeed() const;
	
	bool isMoving() const;
};