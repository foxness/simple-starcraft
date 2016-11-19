#include "game.h"
#include "zealot.h"

Game::Game() : units(std::vector<std::unique_ptr<Unit>>()), selected(0)
{
	units.push_back(std::make_unique<Zealot>(Vector()));
}

void Game::click(const Vector& location, const sf::Mouse::Button& button)
{
	if (button == sf::Mouse::Right)
	{
		units[selected]->startMovingTo(location);
	}
}

void Game::update(float dt)
{
	for (auto& unit : units)
	    unit->update(dt);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.clear();
	for (const auto& unit : units)
		target.draw(*unit, states);
}