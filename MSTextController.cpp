#include "stdafx.h"
#include "MSTextController.h"
#include <iostream>
#include <cstdlib>

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view)
{
	this -> board = &board;
	this -> view = &view;
}

void MSTextController::play()
{
	int x, y;
	char space;

	view -> display();

	while (board -> getGameState() == RUNNING)
	{

		std::cout << "Please enter x, type( 'x' or 'f' ) and y: ";
		std::cin >> x;
		std::cin >> space;
		std::cin >> y;

		x--;
		y--;

		if (space != 'f')
		{
			board -> revealField(x, y);
		}
		else
		{
			board -> toggleFlag(x, y);
		}

		view -> display();
		std::cout << std::endl;

	}

	if (board -> getGameState() == FINISHED_LOSS)
	{
		std::cout << "You lose!" << std::endl;
	}
	else
	{
		std::cout << "You win!" << std::endl;
	}

	getchar();
}