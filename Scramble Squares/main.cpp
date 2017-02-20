#include "square.h"
#include "board.h"
#include "pool.h"
using namespace std;

void SolvePuzzle(Board &, Pool);

int main()
{
	Board TheBoard;
	Pool ThePool;

	SolvePuzzle(TheBoard, ThePool);

	return 0;
}

void SolvePuzzle(Board & TheBoard, Pool ThePool)
{
	if (TheBoard.HowManySquares() < 9)	// if board has 9 squares -> solved
	{
		int start = 0;					// index to start looking for unused squares

		while (start < 9)				// when start is 9, no more squares to try
		{
			int index = ThePool.NextUnusedIndex(start);	// get index of next available square
			Square s = ThePool.GetNextUnused(index);	// get the square at that index
			
			for (int i = 0; i < 4; i++)		// see if square fits in next position
			{								// at each of its rotation configurations
				if (TheBoard.WillFit(s))	// if it fits, add it and update pool
				{
					ThePool.MarkUsed(index);
					TheBoard.AddSquare(s, index);
					SolvePuzzle(TheBoard, ThePool);
					ThePool.MarkUnused(index);	// no solution found, revert board back
					TheBoard.RemoveSquare();
				}
				s.Rotate();					// rotate the piece for next loop
			}
			start = index + 1;				// where to start looking for next square
		}

		return;
	}

	else {
		TheBoard.Display();
		return;
	}
}