#ifndef MSSFMLCONTROLLER_H__
#define MSSFMLCONTROLLER_H__

#include "stdafx.h"

#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

class MSSFMLController
{
private:

	sf::RenderWindow *window;
	MinesweeperBoard* board;
	MSSFMLView* view;

public:

	MSSFMLController(MinesweeperBoard &board, MSSFMLView &view, sf::RenderWindow &window);
	void play(int x, int y, int squareWidth, int sqareHeight, sf::Sprite fieldImage, sf::Sprite flagImage, sf::Sprite mineImage, sf::Text text, sf::Color color );
};

#endif
