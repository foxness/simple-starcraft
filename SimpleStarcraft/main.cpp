#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "unit.h"
#include "game.h"
#include "vector.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	
	Game game;

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

		bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);
		if (!prevPressed && pressed)
		{
			game.click(Vector::from(sf::Mouse::getPosition(window)), sf::Mouse::Right);
		}
		prevPressed = pressed;

		game.update(dt);
		game.draw(window);

		window.display();
	}

	return 0;
}