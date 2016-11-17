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
    
public:
    Entity(Vector position_, float health, int size_);
    
    virtual void draw(sf::RenderWindow& rw) const override;
    
    const Vector& getPosition() const;
    
    float getHealth() const;
    
    int getSize() const;
};