#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "gameObject.h"

class Game : public GameObject
{
private:
    std::vector<GameObject> objects;
    
public:
    Game();
    
    virtual void update(float dt) override;
    
    virtual void draw(sf::RenderWindow& rw) const override;
};