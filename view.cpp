#include "stdafx.h"
#include "view.hpp"

view::view( board &snakeBoard, sf::RenderWindow &window, const char* fieldPath, const char* wallPath, const char* snakePath, const char* foodPath )
{
	this -> snakeBoard = &snakeBoard;
	this -> window = &window;

	foodTexture.loadFromFile(foodPath);
	fieldTexture.loadFromFile(fieldPath);
	wallTexture.loadFromFile(wallPath);
	snakeTexture.loadFromFile(snakePath);
}

void view::draw( int xPos, int yPos, int boardWidth, int boardHeight, int squareWidth, int squareHeight, sf::Color color )
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
			if (snakeBoard->hasWall(x, y))
			{
				fieldImage.setTexture(wallTexture);
			}
			else if (snakeBoard->hasSnake(x, y))
			{
				fieldImage.setTexture(snakeTexture);
			}
			else if (snakeBoard->hasFood(x, y))
			{
				fieldImage.setTexture(foodTexture);
			}
			else
			{
				fieldImage.setTexture(fieldTexture);
			}
			
			fieldImage.setPosition(xPos + x*squareWidth, yPos + y*squareHeight);
			window->draw(fieldImage);
		}
	}
	
	window -> draw(net);
	window -> display();
}
