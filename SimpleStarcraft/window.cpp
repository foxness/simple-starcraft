#include "window.h"
#include <iostream>
#include <map>
#include "constants.h"

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
		float fps = frameTimes.size() / FPS_CALC_PERIOD - 1;

		counter += dt;
		if (counter >= FPS_DISPLAY_PERIOD)
			std::cout << "FPS: " << fps << std::endl;

		while (counter >= FPS_DISPLAY_PERIOD)
			counter -= FPS_DISPLAY_PERIOD;

		if (rw.hasFocus())
		{
			std::map<sf::Mouse::Button, bool> mouse;
			for (const auto& button : prevMouse)
				mouse[button.first] = sf::Mouse::isButtonPressed(button.first);

			game.setMousePosition(sf::Mouse::getPosition(rw));

			if (game.isSelecting() && !mouse[sf::Mouse::Left])
			{
				game.endSelection();
			}
			else if (!prevMouse[sf::Mouse::Left] && mouse[sf::Mouse::Left])
			{
				game.startSelection();
			}
			else if (!prevMouse[sf::Mouse::Right] && mouse[sf::Mouse::Right])
			{
				game.action();
			}

			prevMouse = mouse;
		}

		game.update(dt);

		rw.clear();
		rw.draw(game);

		rw.display();
	}
}
