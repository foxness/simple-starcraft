#include "complexdrawable.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

ComplexDrawable::ComplexDrawable() {}

void ComplexDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& shape : shapes)
	{
		target.draw(*shape, states);
	}
}
