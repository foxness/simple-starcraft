#pragma once

#include "game.h"
#include <queue>

class Window
{
protected:
	Game game;
	sf::RenderWindow rw;
	sf::Clock clock;
	std::queue<float> frameTimes;
	sf::ContextSettings settings;
	float counter = 0;

public:
	Window();

	virtual void mainLoop();
};