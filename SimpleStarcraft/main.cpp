#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "game.h"
#include "vector.h"

int main()
{
	Game game;
	std::queue<float> frameTimes;
	float counter = 0;
	
	sf::Clock clock;
	float prevTime = clock.getElapsedTime().asSeconds();
	bool prevPressed = false;
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close, settings);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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
			game.click(Vector(sf::Mouse::getPosition(window)), sf::Mouse::Right);
		prevPressed = pressed;

		game.update(dt);
		window.draw(game);

		window.display();
	}

	return 0;
}