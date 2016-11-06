#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include "constants.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color::Green);

	sf::Clock clock;
	float prevTime = clock.getElapsedTime().asSeconds();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		float time = clock.getElapsedTime().asSeconds();

		circle.setPosition(time * 10, WINDOW_HEIGHT / 2 + std::sin(time) * 150);
		window.draw(circle);

		float elapsed = time - prevTime;
		prevTime = clock.getElapsedTime().asSeconds();
		float fps = 1 / elapsed;
		std::cout << fps << std::endl;

		window.display();
	}

	return 0;
}