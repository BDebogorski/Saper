#include "stdafx.h"

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "button.h"
#include "menu.h"

int main()
{
	srand(time(NULL));

	sf::Font font;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);

	sf::Color color(200, 200, 200);

	sf::Texture fieldTexture;
	sf::Texture flagTexture;
	sf::Texture mineTexture;

	sf::Sprite fieldImage;
	sf::Sprite flagImage;
	sf::Sprite mineImage;

	if (!fieldTexture.loadFromFile("field.jpg"))
	{
		std::cout << "field file loading error";
	}
	if (!flagTexture.loadFromFile("flag.jpg"))
	{
		std::cout << "flag file loading error";
	}
	if (!mineTexture.loadFromFile("mine.jpg"))
	{
		std::cout << "mine file loading error";
	}
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "font file loading error";
	}

	fieldImage.setTexture(fieldTexture);
	flagImage.setTexture(flagTexture);
	mineImage.setTexture(mineTexture);

	fieldImage.scale(1, 1);
	flagImage.scale(1, 1);
	mineImage.scale(1, 1);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Saper 1.0");

	menu gameMenu;
	gameMenu.addButton("downButton.jpg", "upButton.jpg", 73, 30, 20, 120, 2.3, 2, text, 0, 0, "10x10");
	gameMenu.addButton("downButton.jpg", "upButton.jpg", 73, 30, 20, 190, 2.3, 2, text, 0, 0, "15x15");
	gameMenu.addButton("downButton.jpg", "upButton.jpg", 73, 30, 20, 260, 2.3, 2, text, 0, 0, "20x15");
	gameMenu.addButton("downButton.jpg", "upButton.jpg", 73, 30, 20, 360, 2.3, 2, text, 0, 0, "EASY");
	gameMenu.addButton("downButton.jpg", "upButton.jpg", 73, 30, 20, 430, 2.3, 2, text, 0, 0, "NORMAL");
	gameMenu.addButton("downButton.jpg", "upButton.jpg", 73, 30, 20, 500, 2.3, 2, text, 0, 0, "HARD");
	gameMenu.addButton("downButton.jpg", "upButton.jpg", 73, 30, 600, 500, 2.3, 2, text, 0, 0, "START");

	gameMenu.menuLoop(text, window);

	MinesweeperBoard board(gameMenu.boardWidth, gameMenu.boardHeight, gameMenu.gameMode);
	board.debug_display();
	MSSFMLView view(board, window);
	MSSFMLController ctrl(board, view, window);

	ctrl.play(50, 50, 30, 30, fieldImage, flagImage, mineImage, text, color);
}