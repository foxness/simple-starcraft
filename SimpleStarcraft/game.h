#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.h"
#include "unit.h"
#include <memory>

class Game : public GameObject
{
protected:
    std::vector<std::unique_ptr<Unit>> units;
    int selected;
    
public:
    Game();
    
    virtual void click(const Vector& location, const sf::Mouse::Button& button);
    
    virtual void update(float dt) override;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};