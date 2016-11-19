#include "window.h"
#include <iostream>

const int Window::WINDOW_WIDTH = 800;
const int Window::WINDOW_HEIGHT = 600;
const char* const Window::WINDOW_TITLE = "Simple Starcraft";
const float Window::FPS_CALC_PERIOD = 1;
const float Window::FPS_DISPLAY_PERIOD = 1;

Window::Window()
{
	settings.antialiasingLevel = 8;
	rw.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close, settings);
}

void Window::mainLoop()
{
	float prevTime = clock.getElapsedTime().asSeconds();
	bool prevPressed = false;

	while (rw.isOpen())
	{
		sf::Event event;
		while (rw.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				rw.close();
		}

		float time = clock.getElapsedTime().asSeconds();
		float dt = time - prevTime;
		prevTime = time;

		frameTimes.push(time);
		while (frameTimes.front() < time - FPS_CALC_PERIOD)
			frameTimes.pop();
		float fps = frameTimes.size() / FPS_CALC_PERIOD;

		counter += dt;
		if (counter >= FPS_DISPLAY_PERIOD)
			std::cout << "FPS: " << fps << std::endl;

		while (counter >= FPS_DISPLAY_PERIOD)
			counter -= FPS_DISPLAY_PERIOD;

		bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);
		if (!prevPressed && pressed)
			game.click(Vector(sf::Mouse::getPosition(rw)), sf::Mouse::Right);
		prevPressed = pressed;

		game.update(dt);
		rw.draw(game);

		rw.display();
	}
}
