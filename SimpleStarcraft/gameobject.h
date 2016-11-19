#pragma once

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable
{
public:
	virtual void update(float dt) = 0;
};