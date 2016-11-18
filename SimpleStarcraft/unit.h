#pragma once

#include "vector.h"
#include "entity.h"
#include "SFML/Graphics/Drawable.hpp"
#include <memory>

class Unit : public Entity
{
protected:
	std::unique_ptr<sf::Drawable> drawable;
	Vector destination;
	Vector moveVector;
	float moveSpeed;
	bool moving;

	Unit(const Vector& position_, int size_, float moveSpeed_);

public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
	
    virtual void update(float dt) override;
	
	void startMovingTo(const Vector& location);
	
	float getMovespeed() const;
	
	bool isMoving() const;
};