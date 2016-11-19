#pragma once

#include <SFML/Graphics.hpp>
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
	static const int WINDOW_WIDTH;
	static const int WINDOW_HEIGHT;
	static const char* const WINDOW_TITLE;
	static const float FPS_CALC_PERIOD;
	static const float FPS_DISPLAY_PERIOD;

	Window();

	virtual void mainLoop();
};