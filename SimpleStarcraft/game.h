#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "vector.h"

class Game : public GameObject
{
private:
    std::vector<Unit> units;
    int selected;
    
public:
    Game();
    
    virtual void click(const Vector& location, const sf::Mouse::Button& button);
    
    virtual void update(float dt) override;
    
    virtual void draw(sf::RenderWindow& rw) const override;
};