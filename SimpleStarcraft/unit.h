#pragma once

#include "vector.h"
#include "entity.h"

class Unit : public Entity
{
private:
	Vector destination;
	Vector moveVector;
	float moveSpeed;
	bool moving;

public:
	Unit(const Vector& position_ = Vector(), float health_ = 10, int size_ = 50, float moveSpeed_ = 120);
	
    virtual void update(float dt) override;
	
	void startMovingTo(const Vector& location);
	
	float getMovespeed() const;
	
	bool isMoving() const;
};