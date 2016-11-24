#include "game.h"
#include "zealot.h"
#include "rectangle.h"
#include "nexus.h"
#include "mineralpatch.h"
#include "probe.h"
#include <iostream>
#include <cassert>

Game::Game() : ec(units, structures, resources, selectedEntities)
{
	structures.push_back(std::make_shared<Nexus>(Vector(400, 500)));

	units.push_back(std::make_shared<Zealot>(Vector(200, 300)));
	units.push_back(std::make_shared<Probe>(Vector(200, 350)));

	resources.push_back(std::make_shared<MineralPatch>(Vector(450, 300)));
}

void Game::printSelected() const
{
	std::cout << "SELECTED: ";
	for (const auto& entity : selectedEntities)
		std::cout << *entity << " ";
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

	selectedEntities.clear();

	for (const auto& unit : units)
		if (rect.contains(unit->getPosition()))
			selectedEntities.push_back(unit);

	if (selectedEntities.size() == 0)
	{
		for (const auto& structure : structures)
			if (rect.contains(structure->getPosition()))
				selectedEntities.push_back(structure);
	}

	printSelected();
	selecting = false;
}

void Game::action()
{
	ec.action(mousePosition);
}

bool Game::isSelecting() const
{
	return selecting;
}

void Game::update(float dt)
{
	ec.update(dt);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& resource : resources)
	{
		target.draw(*resource, states);
	}

	for (const auto& structure : structures)
	{
		target.draw(*structure, states);
		structure->drawHealthbar(target, states);
	}

	for (const auto& unit : units)
	{
		target.draw(*unit, states);
		unit->drawHealthbar(target, states);
	}

	for (const auto& selected : selectedEntities)
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