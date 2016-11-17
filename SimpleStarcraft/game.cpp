#include "game.h"
#include "unit.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "vector.h"
#include <iostream>

Game::Game() : units(std::vector<Unit>()), selected(0)
{
	units.push_back(Unit());
}

void Game::click(const Vector& location, const sf::Mouse::Button& button)
{
	if (button == sf::Mouse::Right)
	{
		units[selected].startMovingTo(location);
	}
}

void Game::update(float dt)
{
	for (auto& unit : units)
	    unit.update(dt);
}

void Game::draw(sf::RenderWindow& rw) const
{
	rw.clear();
	for (const auto& unit : units)
	    unit.draw(rw);
}