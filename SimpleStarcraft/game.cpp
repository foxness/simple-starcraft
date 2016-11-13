#include "game.h"
#include "unit.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "vector.h"

Game::Game() : units(vector<Unit>()), selected(0)
{
	units.push_back(Unit());
}

virtual void Game::click(const Vector& location, const sf::Mouse::Button& button)
{
	if (button == sf::Mouse::Right)
	    units[selected].startMovingTo(location);
}

virtual void Game::update(float dt) override
{
	for (auto& unit : units)
	    unit.update(dt);
}

virtual void Game::draw(sf::RenderWindow& rw) const override
{
	rw.clear();
	for (const auto& unit : units)
	    unit.draw(rw);
}