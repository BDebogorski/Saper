#ifndef BOARD_HPP__
#define BOARD_HPP__

#include "stdafx.h"
#include <vector>

enum direction { STOP, LEFT, RIGHT, UP, DOWN };
enum state { RUNNING, OVER };

class board
{

    struct pos
    {
        int x;
        int y;
    };

    struct field
    {
        bool hasFood;
        bool hasSnake;
        bool hasWall;

        field()
        {
            hasFood = 0;
            hasSnake = 0;
            hasWall = 0;
        }
    };

    private:

        int prevX;
        int prevY;
        state gameState;

        std::vector <pos> snake;
        field boardTab[100][100];
        direction snakeDirection;

        int width;
        int height;

        void addFood();
        void addPart();

    public:

        board( int width, int height, int xPos, int yPos );
        void showTextBoard() const;
        void setDirection( direction side );
        bool move();

        bool hasSnake( int x, int y ) const;
        bool hasFood( int x, int y ) const;
        bool hasWall( int x, int y ) const;
		int getWidth() const;
		int getHeight() const;
        state getState() const;

};

#endif // BOARD_HPP__
