#include "stdafx.h"
#include "MSSFMLView.h"

MSSFMLView::MSSFMLView( MinesweeperBoard &board, sf::RenderWindow &window )
{
	this -> board = &board;
	this -> window = &window;
}

void MSSFMLView::draw( int xPos, int yPos, int boardWidth, int boardHeight, int squareWidth, int squareHeight, sf::Sprite fieldImage, sf::Sprite flagImage, sf::Sprite mineImage, sf::Text text, sf::Color color )
{
	std::string num;
	sf::VertexArray net( sf::Lines );

	for ( int y = 0; y <= boardHeight; y++ )
	{
		sf::Vertex first, second;
		first.position = sf::Vector2f(xPos, yPos + y*squareHeight );
		second.position = sf::Vector2f(xPos + boardWidth*squareWidth, yPos + y*squareHeight );

		first.color = color;
		second.color = color;

		net.append(first);
		net.append(second);
	}

	for ( int x = 0; x <= boardWidth; x++ )
	{
		sf::Vertex first, second;
		first.position = sf::Vector2f(xPos + x*squareWidth, yPos);
		second.position = sf::Vector2f(xPos + x*squareWidth, yPos + boardHeight*squareHeight);

		first.color = color;
		second.color = color;

		net.append(first);
		net.append(second);
	}

	for (int y = 0; y < boardHeight; y++)
	{
		for (int x = 0; x < boardWidth; x++)
		{
			if ( board -> isRevealed( x, y ) )
			{
				text.setPosition(xPos + x*squareWidth + 8, yPos + y*squareHeight);
				num = board->countMines(x, y) + 48;
				text.setString(num);
				window -> draw(text);
			}
			else
			{
				fieldImage.setPosition(xPos + x*squareWidth, yPos + y*squareHeight);
				window->draw(fieldImage);
			}

			if ( board -> hasFlag( x, y ) )
			{
				flagImage.setPosition(xPos + x*squareWidth, yPos + y*squareHeight);
				window -> draw(flagImage);
			}

			if (board->getGameState() == FINISHED_LOSS && board->hasMine(x,y))
			{
				mineImage.setPosition(xPos + x*squareWidth, yPos + y*squareHeight);
				window->draw(mineImage);
			}
		}
	}
	
	window -> draw(net);
	window -> display();
}
