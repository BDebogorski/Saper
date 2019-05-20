#ifndef VIEW_HPP__
#define VIEW_HPP__

#include "stdafx.h"
#include "board.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class view
{
	private:

		sf::RenderWindow* window;
		board* snakeBoard;

		sf::Sprite fieldImage;

		sf::Texture fieldTexture;
		sf::Texture wallTexture;
		sf::Texture snakeTexture;
		sf::Texture foodTexture;

	public:

		view( board &snakeBoard, sf::RenderWindow &window, const char* fieldPath, const char* wallPath, const char* snakePath, const char* foodPath );
		void draw( int x, int y, int boardWidth, int boardHeight, int squareWidth, int sqareHeight, sf::Color color );
};

#endif