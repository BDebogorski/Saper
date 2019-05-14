#ifndef MSSFMLVIEW_H__
#define MSSFMLVIEW_H__

#include "stdafx.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include "button.h"
#include <vector>

class MSSFMLView
{
	private:

		sf::RenderWindow* window;
		MinesweeperBoard* board;

	public:

		MSSFMLView( MinesweeperBoard &board, sf::RenderWindow &window );
		void draw( int x, int y, int boardWidth, int boardHeight, int squareWidth, int sqareHeight, sf::Sprite fieldImage, sf::Sprite flagImage, sf::Sprite mineImage, sf::Text text, sf::Color color );
};

#endif