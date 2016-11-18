#pragma once

#include <SFML/Graphics.hpp>
#include "vector.h"
#include "gameobject.h"

class Entity : public GameObject
{
protected:
    Vector position;
    int size;

	Entity(Vector position_, int size_);
    
public:
    const Vector& getPosition() const;
    
    int getSize() const;
};