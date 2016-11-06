#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Simple Starcraft");
	sf::CircleShape shape(200.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);

		std::cout << clock.getElapsedTime().asSeconds() << std::endl;

		window.display();
	}

	return 0;
}