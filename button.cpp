#include "stdafx.h"
#include "button.h"
#include <iostream>
button::button( const char* downPath, const char* upPath, int width, int height, int x, int y, double xScale, double yScale, sf::Text text, int xOffset, int yOffset, std::string name )
{
	this -> text = text;
	this -> width = width;
	this -> height = height;
	this -> x = x;
	this -> y = y;

	
	std::cout << upTexture.loadFromFile(upPath);
	downTexture.loadFromFile(downPath);

	upImage.setTexture(upTexture);
	downImage.setTexture(downTexture);

	this -> width *= xScale;
	this -> height *= yScale;

	upImage.scale(xScale, yScale);
	downImage.scale(xScale, yScale);

	upImage.setPosition(x, y);
	downImage.setPosition(x, y);

	text.setPosition(xOffset + x, yOffset + y);
	text.setString(name);

	state = false;
}

bool button::isInButton(int xPos, int yPos) const
{
	if (xPos > x && xPos < x + width && yPos > y && yPos < y + height)
	{
		return true;
	}

	return false;
}

bool button::push( sf::RenderWindow &window )
{
	state = !state;
	//show(window);
	return state;
}

bool button::getState() const
{
	return state;
}

void button::show(sf::RenderWindow &window )
{
	if (state == true)
	{
		window.draw(downImage);
	}
	else
	{
		window.draw(upImage);
	}

	window.draw(text);
	//window.display();
}