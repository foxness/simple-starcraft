#pragma once

#include <SFML/Graphics.hpp>
#include "vector.h"
#include "gameobject.h"

class Entity : public GameObject
{
protected:
    Vector position;
    float health;
    int size;

	Entity(Vector position_, float health, int size_);
    
public:
    const Vector& getPosition() const;
    
    float getHealth() const;
    
    int getSize() const;
};