#include "stdafx.h"
#include "MinesweeperBoard.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

MinesweeperBoard::field::field()
{
    hasMine = false;
    hasFlag = false;
    isRevealed = false;
}

MinesweeperBoard::MinesweeperBoard( int width, int height, GameMode mode )
{

    isFinished = false;
    isFirst = true;

    this -> width = width;
    this -> height = height;
    this -> mode = mode;

    if( mode == 0 )
    {
        loadFromFile();
    }
    else
    {
        setRandomMines( mode );
    }

}

bool MinesweeperBoard::isInBoard( int x, int y ) const
{
    if( x < width && x >= 0 && y < height && y >= 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

GameState MinesweeperBoard::getGameState() const
{
    if( isFinished )
    {
        return FINISHED_LOSS;
    }

    if( finishedWin() )
    {
        return FINISHED_WIN;
    }

    return RUNNING;
}

bool MinesweeperBoard::finishedWin() const
{

    for( int y = 0; y < height; y++ )
    {
        for( int x = 0; x < width; x++ )
        {
            if((board[x][y].hasFlag && !board[x][y].hasMine) ||
            (board[x][y].hasMine && !board[x][y].hasFlag) || 
			(!board[x][y].isRevealed && !board[x][y].hasMine) )
            {
                return false;
            }
        }
    }

    return true;
}

bool MinesweeperBoard::isRevealed(int x, int y) const
{
    return board[x][y].isRevealed;
}

void MinesweeperBoard::setRandomMines( int procent )
{
	int x;
	int y;

	minesNumber = 0;

	for (int i = 0; i < width*height*procent/100; i++)
	{
		do
		{
			x = rand() % ( width );
			y = rand() % ( height );
		} 
		while ( board[x][y].hasMine );

		board[x][y].hasMine = true;
		minesNumber++;
	}
}

int MinesweeperBoard::countMines( int x, int y ) const
{

    if( !board[x][y].isRevealed || !isInBoard( x, y ) )
    {
        return -1;
    }

    int quantity = 0;

    for( int localX = x - 1; localX < x + 2; localX++ )
    {
        for( int localY = y - 1; localY < y + 2; localY++ )
        {
            if( isInBoard( localX, localY ) && ( x != localX || y != localY ) )
            {
                quantity += board[localX][localY].hasMine;
            }
        }
    }

    return quantity;
}

bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if( !isInBoard( x, y ) || board[x][y].isRevealed || !board[x][y].hasFlag )
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool MinesweeperBoard::hasMine(int x, int y) const
{
	return board[x][y].hasMine;
}

void MinesweeperBoard::toggleFlag(int x, int y)
{

    if( isInBoard( x, y ) && !board[x][y].isRevealed && !isFinished )
    {
        board[x][y].hasFlag = !board[x][y].hasFlag;
    }
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getMineCount() const
{
    return minesNumber;
}

void MinesweeperBoard::recurrentRevealField(int x, int y)
{
	int localX;
	int localY;

	board[x][y].isRevealed = true;

	if (countMines(x, y) == 0)
	{
		for (int localX = x - 1; localX < x + 2; localX++)
		{
			for (int localY = y - 1; localY < y + 2; localY++)
			{
				if (isInBoard(localX, localY) && (x != localX || y != localY) && board[localX][localY].isRevealed == false && board[localX][localY].hasFlag == false)
				{
					revealField(localX, localY);
					recurrentRevealField(localX, localY);
				}
			}
		}
	}
}

void MinesweeperBoard::revealField(int x, int y)
{

    if( !board[x][y].isRevealed && !board[x][y].hasFlag && isInBoard( x, y ) && !isFinished )
    {
        if( board[x][y].hasMine )
        {
            if( mode != DEBUG && isFirst )
            {
                moveMine(x, y);
				recurrentRevealField(x, y);
            }
            else
            {
                isFinished = true;
            }
        }
        else
        {
			recurrentRevealField(x, y);
        }
    }

    isFirst = false;
}

void MinesweeperBoard::moveMine( int x, int y )
{
    int newX;
    int newY;

    do
    {
        newX = rand() % width;
        newY = rand() % height;
    }
    while( board[newX][newY].hasMine );

	board[newX][newY].hasMine = true;
	board[x][y].hasMine = false;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if( !isInBoard( x, y ) )
    {
        return '#';
    }

    if( !board[x][y].isRevealed && board[x][y].hasFlag )
    {
        return 'F';
    }

    if( !board[x][y].isRevealed && !board[x][y].hasFlag )
    {
        return '_';
    }

    if( board[x][y].isRevealed && board[x][y].hasMine )
    {
        return 'X';
    }

    if( board[x][y].isRevealed && countMines(x, y) == 0 )
    {
        return ' ';
    }

	return countMines(x, y) + '0';

}

void MinesweeperBoard::debug_display() const
{
    for( int y = 0; y < height; y++ )
    {
        for( int x = 0; x < width; x++ )
        {
            std::cout << "[";

            if( true == board[x][y].hasMine )
            {
                std::cout << "M ";
            }
            else
            {
                std::cout << ". ";
            }

            if( true == board[x][y].isRevealed )
            {
                std::cout << "o ";
            }
            else
            {
                std::cout << ". ";
            }

            if( true == board[x][y].hasFlag )
            {
                std::cout << "f]";
            }
            else
            {
                std::cout << ".]";
            }

        }
        std::cout << std::endl;
    }
}

void MinesweeperBoard::loadFromFile()
{
    char mine;
    char flag;
    char revealed;
    char space;

    std::fstream file;
    file.open( "board.txt" );

    for( int y = 0; y < height; y++ )
    {
        for( int x = 0; x < width; x++ )
        {
            file >> space;
            file >> mine;
            file >> revealed;
            file >> flag;
            file >> space;

            if( mine == 'M' )
            {
                board[x][y].hasMine = true;
            }

            if( revealed == 'o' )
            {
                board[x][y].isRevealed = true;
            }

            if( flag == 'f' )
            {
                board[x][y].hasFlag = true;
            }

        }

    }

    file.close();
}
