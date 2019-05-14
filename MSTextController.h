#ifndef MSTEXTCONTROLLER_H__
#define MSTEXTCONTROLLER_H__

#include "stdafx.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
	private:

		MinesweeperBoard* board;
		MSBoardTextView* view;

	public:

		MSTextController( MinesweeperBoard &board, MSBoardTextView &view );
		void play();

};

#endif
