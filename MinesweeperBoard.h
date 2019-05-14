#ifndef MINESWEEPERBOARD_H__
#define MINESWEEPERBOARD_H__

#include "stdafx.h"

enum GameMode { DEBUG = 0, EASY = 10, NORMAL = 20, HARD = 30 };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class MinesweeperBoard
{
    private:

        struct field
        {

            bool hasMine;
            bool hasFlag;
            bool isRevealed;

            field();

        };

        int width;
        int height;
        int minesNumber;
        bool isFinished;
        bool isFirst;

        GameMode mode;
        field board[100][100];

        void loadFromFile();
        void setRandomMines( int procent );
        bool isInBoard( int x, int y ) const;
        bool finishedWin() const;
        void moveMine( int x, int y );
		void recurrentRevealField(int x, int y);

    public:

        int getBoardWidth() const;
        int getBoardHeight() const;
        int getMineCount() const;
        bool isRevealed(int x, int y) const;

        int countMines( int x, int y ) const;
        bool hasFlag(int x, int y) const;
		bool hasMine(int x, int y) const;
        void toggleFlag(int x, int y);
        void revealField(int x, int y);
        char getFieldInfo(int x, int y) const;
        GameState getGameState() const;

        void debug_display() const;

        MinesweeperBoard( int width = 8, int height = 8, GameMode mode = NORMAL );

};

#endif
