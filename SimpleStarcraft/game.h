#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "gameobject.h"
#include "vector.h"
#include "unit.h"

class Game : public GameObject
{
protected:
    std::vector<Unit> units;
    int selected;
    
public:
    Game();
    
    virtual void click(const Vector& location, const sf::Mouse::Button& button);
    
    virtual void update(float dt) override;
    
    virtual void draw(sf::RenderWindow& rw) const override;
};