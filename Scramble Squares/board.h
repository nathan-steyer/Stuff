#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board();
	int HowManySquares();
	bool WillFit(Square &);
	void AddSquare(Square &, int);
	void RemoveSquare();
	void Display();

private:
	Square grid[3][3];
	char SquareNames[3][3];
	int numSquares;
};

#endif
