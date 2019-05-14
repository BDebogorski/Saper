#ifndef MSBOARDTEXTVIEW_H__
#define MSBOARDTEXTVIEW_H__

#include "stdafx.h"
#include "MinesweeperBoard.h"
#include <iostream>

class MSBoardTextView
{
    private:

        MinesweeperBoard* board;

    public:

        MSBoardTextView( MinesweeperBoard &board );
        void display() const;

};

#endif
