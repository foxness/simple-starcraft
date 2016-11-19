#include "game.h"
#include "zealot.h"
#include "rectangle.h"
#include <iostream>
#include <typeinfo>

Game::Game() : units(std::vector<std::shared_ptr<Unit>>()), selectedUnits(std::vector<std::shared_ptr<Unit>>())
{
	auto z = std::make_shared<Zealot>(Vector());
	units.push_back(z);
	selectedUnits.push_back(z);
}

void Game::printSelected() const
{
	std::cout << "selected: ";
	for (const auto& unit : selectedUnits)
		std::cout << typeid(*unit).name() << " ";
	std::cout << std::endl;
}

void Game::select(const Vector& start, const Vector& end)
{
	auto rect = Rectangle(start, end);
	selectedUnits.clear();
	for (const auto& unit : units)
		if (rect.contains(unit->getPosition()))
			selectedUnits.push_back(unit);
	printSelected();
}

void Game::moveSelected(const Vector& location)
{
	for (auto& selected : selectedUnits)
		selected->startMovingTo(location);
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