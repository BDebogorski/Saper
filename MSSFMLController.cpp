#include "stdafx.h"

#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(MinesweeperBoard &board, MSSFMLView &view, sf::RenderWindow &window )
{
	this -> window = &window;
	this -> board = &board;
	this -> view = &view;
}

void MSSFMLController::play(int xPos, int yPos, int squareWidth, int squareHeight, sf::Sprite fieldImage, sf::Sprite flagImage, sf::Sprite mineImage, sf::Text text, sf::Color color )
{

	while (window -> isOpen() && board -> getGameState() == RUNNING )
	{
		sf::Event event;

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					board->toggleFlag((event.mouseButton.x - xPos) / squareWidth, (event.mouseButton.y - yPos) / squareHeight);
				}

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					board->revealField((event.mouseButton.x - xPos) / squareWidth, (event.mouseButton.y - yPos) / squareHeight);
				}
			}
		}

		window->clear();
		view->draw(xPos, yPos, board->getBoardWidth(), board->getBoardHeight(), squareWidth, squareHeight, fieldImage, flagImage, mineImage, text, color);
	}
}