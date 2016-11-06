#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "unit.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color::Green);

	Unit a;

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

		float time = clock.getElapsedTime().asSeconds();
		float dt = time - prevTime;
		prevTime = clock.getElapsedTime().asSeconds();

		window.clear();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			auto mousePosition = sf::Mouse::getPosition(window);
			a.move(mousePosition.x, mousePosition.y);
		}

		a.update(dt);

		circle.setPosition(a.getPosition());
		window.draw(circle);

		window.display();
	}

	return 0;
}