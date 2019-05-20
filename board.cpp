#include "stdafx.h"
#include "board.hpp"
#include <cstdlib>

board::board( int width, int height, int xPos, int yPos )
{
    this -> width = width;
    this -> height = height;

    gameState = RUNNING;
	snakeDirection = STOP;

    snake.push_back( pos() );
    snake[0].x = xPos;
    snake[0].y = yPos;

    for( int y = 0; y < height; y++ )
    {
        for( int x = 0; x < width; x++ )
        {
            if( x < 1 || x > width-2 || y < 1 || y > height-2 )
            {
                boardTab[x][y].hasWall = true;
            }
        }
    }

    boardTab[snake[0].x][snake[0].y].hasSnake = true;
    addFood();
}

void board::addFood()
{
    int x;
    int y;

    do
    {
        x = rand() % ( width - 2) + 1;
        y = rand() % ( height - 2) + 1;
    }
    while( boardTab[x][y].hasSnake == true );

    boardTab[x][y].hasFood = true;
}

bool board::move()
{

	if (snakeDirection == STOP)
	{
		return false;
	}

    int tmpX;
    int tmpY;

    for( unsigned i = 0; i < snake.size(); i++ )
    {
        boardTab[snake[i].x][snake[i].y].hasSnake = false;

        if( i == 0 )
        {
            prevX = snake[0].x;
            prevY = snake[0].y;

            switch( snakeDirection )
            {
                case UP:
                    snake[0].y--;
                    break;

                case DOWN:
                    snake[0].y++;
                    break;

                case RIGHT:
                    snake[0].x++;
                    break;

                case LEFT:
                    snake[0].x--;
                    break;
            }

            if( snake.size() > 1 )
            {
                for( unsigned i = 2; i < snake.size(); i++ )
                {
                    if( snake[i].x == snake[0].x && snake[i].y == snake[0].y )
                    {
                        gameState = OVER;
                        return false;
                    }
                }
            }

            if( snake.size() > 1 && snake[0].x == snake[1].x && snake[0].y == snake[1].y )
            {
                boardTab[prevX][prevY].hasSnake = true;
                snake[0].x = prevX;
                snake[0].y = prevY;
                return false;
            }
        }
        else
        {
            tmpX = prevX;
            tmpY = prevY;

            prevX = snake[i].x;
            prevY = snake[i].y;

            snake[i].x = tmpX;
            snake[i].y = tmpY;
        }

        boardTab[snake[i].x][snake[i].y].hasSnake = true;
    }

    if( boardTab[snake[0].x][snake[0].y].hasFood == true )
    {
        addPart();
        boardTab[snake[0].x][snake[0].y].hasFood = false;
        addFood();
    }

    if( boardTab[snake[0].x][snake[0].y].hasWall == true )
    {
        gameState = OVER;
        return false;
    }

    return true;
}

void board::addPart()
{
    snake.push_back( pos() );
    snake[snake.size() - 1].x = prevX;
    snake[snake.size() - 1].y = prevY;

    boardTab[prevX][prevY].hasSnake = true;
}

void board::setDirection( direction side )
{
    snakeDirection = side;
}

bool board::hasSnake( int x, int y ) const
{
    return boardTab[x][y].hasSnake;
}

bool board::hasFood( int x, int y ) const
{
    return boardTab[x][y].hasFood;
}

bool board::hasWall( int x, int y ) const
{
    return boardTab[x][y].hasWall;
}

int board::getWidth() const
{
	return width;
}

int board::getHeight() const
{
	return height;
}

state board::getState() const
{
    return gameState;
}