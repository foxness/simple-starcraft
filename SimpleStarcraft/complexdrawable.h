#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class ComplexDrawable : public sf::Drawable
{
protected:
	std::vector<std::shared_ptr<sf::Shape>> shapes;

	ComplexDrawable();

public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};