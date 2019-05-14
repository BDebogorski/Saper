#ifndef MENU_H__
#define MENU_H__

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "button.h"
#include <vector>
#include "MinesweeperBoard.h"

enum WindowState { GAME, MENU };

class menu
{

	private:

		std::vector <button> menuButton;
		void drawMenu(sf::Text text, sf::RenderWindow &window);

	public:

		int boardWidth;
		int boardHeight;

		WindowState winState;
		GameMode gameMode;

		menu();
		void menuLoop(sf::Text text, sf::RenderWindow &window);
		void addButton(const char* downPath, const char* upPath, int width, int height, int x, int y, double xScale, double yScale, sf::Text text, int xOffset, int yOffset, std::string name);
};

#endif
