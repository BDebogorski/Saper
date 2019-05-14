#ifndef BUTTON_H__
#define BUTTON_H__

#include "stdafx.h"
#include <SFML/Graphics.hpp>

class button
{

private:

	int x;
	int y;
	int width;
	int height;
	bool state;

	sf::RenderWindow *window;

	sf::Text text;
	sf::Texture upTexture;
	sf::Texture downTexture;
	sf::Sprite upImage;
	sf::Sprite downImage;

public:

	button( const char* downPath, const char* upPath, int width, int height, int x, int y, double xScale, double yScale, sf::Text text, int xOffset, int yOffset, std::string name );
	bool isInButton(int x, int y) const;
	bool push( sf::RenderWindow &window );
	void show(sf::RenderWindow &window);
	bool getState() const;
};

#endif
