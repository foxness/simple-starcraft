#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.h"
#include "unit.h"
#include <memory>

class Game : public GameObject
{
protected:
    std::vector<std::shared_ptr<Unit>> units;
	std::vector<std::shared_ptr<Unit>> selectedUnits;
    
public:
    Game();

	void printSelected() const;

	void select(const Vector& start, const Vector& end);
    
    void moveSelected(const Vector& location);
    
    virtual void update(float dt) override;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};