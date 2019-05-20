#include "stdafx.h"
#include "board.hpp"
#include "view.hpp"
#include <ctime>

int main()
{

    srand(time(NULL));

    board snakeBoard( 40, 40, 10, 10 );
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake 1.0");
	view snakeView(snakeBoard, window, "field.png", "wall.png", "snake.png", "food.png" );
	sf::Color color(200, 200, 200);

	sf::Clock mainClock;

	while (window.isOpen() && snakeBoard.getState() == RUNNING)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					snakeBoard.setDirection( UP );
					break;

				case sf::Keyboard::S:
					snakeBoard.setDirection(DOWN);
					break;

				case sf::Keyboard::A:
					snakeBoard.setDirection(LEFT);
					break;

				case sf::Keyboard::D:
					snakeBoard.setDirection(RIGHT);
					break;
				}
			}
		}

		if (mainClock.getElapsedTime() >= sf::milliseconds(100) )
		{
			snakeBoard.move();
			mainClock.restart();
		}

		window.clear();
		snakeView.draw(50, 50, snakeBoard.getWidth(), snakeBoard.getHeight(), 10, 10, color);
	}
}
