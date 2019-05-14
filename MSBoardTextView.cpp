#include "stdafx.h"
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView( MinesweeperBoard &board )
{
    this -> board = &board;
}

void MSBoardTextView::display() const
{
    for( int y = 0; y < board -> getBoardHeight(); y++ )
    {
        for( int x = 0; x < board -> getBoardWidth(); x++ )
        {
            std::cout << board -> getFieldInfo(x, y) << " ";
        }
        std::cout << std::endl;
    }
}
