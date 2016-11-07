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
	bool prevPressed = false;
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

		bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);

		if (!prevPressed && pressed)
		{
			auto mousePosition = sf::Mouse::getPosition(window);
			a.startMovingTo(mousePosition.x, mousePosition.y);
		}

		prevPressed = pressed;

		a.update(dt);

		auto pos = a.getPosition();
		circle.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
		window.draw(circle);

		window.display();
	}

	return 0;
}