#include "game.h"
#include "unit.h"
#include <vector>
#include <SFML/Graphics.hpp>

Game::Game() : objects()
{
	objects.push_back(Unit());
}

void Game::update(float dt) override
{
	for (auto& object : objects)
	    object.update(dt);
}

void Game::draw(sf::RenderWindow& rw) const override
{
	for (const auto& object : objects)
	    object.draw(rw);
}