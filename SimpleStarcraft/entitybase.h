#pragma once

#include <SFML/Graphics.hpp>
#include "vector.h"
#include "gameobject.h"

class EntityBase : public GameObject
{
protected:
    Vector position;

	EntityBase(const Vector& position_);
    
public:
    const Vector& getPosition() const;

	int getId() const;

	bool operator==(const EntityBase& other) const;

	bool operator!=(const EntityBase& other) const;

private:
	int id;
	int getNextId() const;
};