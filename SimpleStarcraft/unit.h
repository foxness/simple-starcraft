#pragma once

#include "entity.h"

class Unit : public Entity
{
protected:
	Vector destination;
	Vector moveVector;
	float moveSpeed;
	bool moving;

	Unit(const Vector& position_, int size_, float health_, float moveSpeed_);

public:
    virtual void update(float dt) override;
	
	void startMovingTo(const Vector& location);
	
	float getMovespeed() const;
	
	bool isMoving() const;
};