#include "window.h"
#include <iostream>
#include <map>

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

	std::map<sf::Mouse::Button, bool> prevMouse =
	{
		{ sf::Mouse::Left, false },
		{ sf::Mouse::Right, false },
		{ sf::Mouse::Middle, false },
	};

	Vector selectionStart;
	bool selecting = false;

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

		std::map<sf::Mouse::Button, bool> mouse;
		for (const auto& button : prevMouse)
			mouse[button.first] = sf::Mouse::isButtonPressed(button.first);

		if (selecting && !mouse[sf::Mouse::Left])
		{
			game.select(selectionStart, Vector(sf::Mouse::getPosition(rw)));
			selecting = false;
		}
		else if (!prevMouse[sf::Mouse::Left] && mouse[sf::Mouse::Left])
		{
			selectionStart = Vector(sf::Mouse::getPosition(rw));
			selecting = true;
		}
		else if (!prevMouse[sf::Mouse::Right] && mouse[sf::Mouse::Right])
		{
			game.moveSelected(Vector(sf::Mouse::getPosition(rw)));
		}

		prevMouse = mouse;

		game.update(dt);
		rw.draw(game);

		rw.display();
	}
}
