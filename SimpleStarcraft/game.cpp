#include "game.h"
#include "zealot.h"
#include "rectangle.h"
#include <iostream>
#include <typeinfo>
#include <cassert>

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

void Game::setMousePosition(const Vector& mousePosition_)
{
	mousePosition = mousePosition_;
}

void Game::startSelection()
{
	assert(!selecting);
	selectionStart = mousePosition;
	selecting = true;
}

void Game::endSelection()
{
	assert(selecting);
	auto rect = Rectangle(selectionStart, mousePosition);
	selectedUnits.clear();
	for (const auto& unit : units)
		if (rect.contains(unit->getPosition()))
			selectedUnits.push_back(unit);
	printSelected();
	selecting = false;
}

void Game::moveSelected(const Vector& location)
{
	for (auto& selected : selectedUnits)
		selected->startMovingTo(location);
}

bool Game::isSelecting() const
{
	return selecting;
}

void Game::update(float dt)
{
	for (auto& unit : units)
	    unit->update(dt);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& unit : units)
		target.draw(*unit, states);

	for (const auto& selected : selectedUnits)
		selected->drawSelection(target);

	if (selecting)
	{
		auto selection = Rectangle(selectionStart, mousePosition);
		sf::VertexArray selectionVA(sf::LinesStrip, 5);
		selectionVA[0].position = selection.getPosition();
		selectionVA[1].position = selectionVA[0].position + sf::Vector2f(selection.getWidth(), 0);
		selectionVA[2].position = selectionVA[1].position + sf::Vector2f(0, selection.getHeight());
		selectionVA[3].position = selectionVA[2].position + sf::Vector2f(-selection.getWidth(), 0);
		selectionVA[4].position = selectionVA[0].position;

		target.draw(selectionVA, states);
	}
}