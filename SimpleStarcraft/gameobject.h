#pragma once

#include <SFML/Graphics.hpp>
#include "updatable.h"

class GameObject : public sf::Drawable, public Updatable
{
};