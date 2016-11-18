#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class GameObject : public sf::Drawable
{
public:
	virtual void update(float dt) = 0;
};