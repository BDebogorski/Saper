#include "stdafx.h"
#include "menu.h"

menu::menu()
{
	winState = MENU;
	boardHeight = 10;
	boardWidth = 10;
	gameMode = EASY;
}

void menu::drawMenu(sf::Text text, sf::RenderWindow &window)
{
	text.setCharacterSize(60);
	text.setPosition(20, 10);
	text.setString("Saper");
	window.draw(text);

	text.setCharacterSize(15);
	text.setPosition(20, 90);
	text.setString("Blazej Debogorski 242689");
	window.draw(text);
	
	for (int i = 0; i < menuButton.size(); i++)
	{
		menuButton[i].show(window);
	}
}

void menu::menuLoop(sf::Text text, sf::RenderWindow &window)
{
	WindowState winState = MENU;

	while (winState == MENU && window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (menuButton[0].isInButton(event.mouseButton.x, event.mouseButton.y) == true)
				{
					menuButton[0].push(window);
					boardWidth = 10;
					boardHeight = 10;
				}

				if (menuButton[1].isInButton(event.mouseButton.x, event.mouseButton.y) == true)
				{
					menuButton[1].push(window);
					boardWidth = 15;
					boardHeight = 15;
				}

				if (menuButton[2].isInButton(event.mouseButton.x, event.mouseButton.y) == true)
				{
					menuButton[2].push(window);
					boardWidth = 20;
					boardHeight = 15;
				}

				if (menuButton[3].isInButton(event.mouseButton.x, event.mouseButton.y) == true)
				{
					menuButton[3].push(window);
					gameMode = EASY;
				}

				if (menuButton[4].isInButton(event.mouseButton.x, event.mouseButton.y) == true)
				{
					menuButton[4].push(window);
					gameMode = NORMAL;
				}

				if (menuButton[5].isInButton(event.mouseButton.x, event.mouseButton.y) == true)
				{
					menuButton[5].push(window);
					gameMode = HARD;
				}

				if (menuButton[6].isInButton(event.mouseButton.x, event.mouseButton.y) == true)
				{
					winState = GAME;
				}
			}
		}

		window.clear();
		drawMenu(text, window);
		window.display();
	}
}

void menu::addButton(const char* downPath, const char* upPath, int width, int height, int x, int y, double xScale, double yScale, sf::Text text, int xOffset, int yOffset, std::string name)
{
	menuButton.push_back( button(downPath, upPath, width, height, x, y, xScale, yScale, text, xOffset, yOffset, name) );
}