#include "square.h"
#include "board.h"
#include <iostream>
using namespace std;

// initialize board to be blank
Board::Board()
{
	numSquares = 0;
}

// returns the number of squares on the board
int Board::HowManySquares() { return numSquares; }

// determines if the square passed will fit into the next position
bool Board::WillFit(Square & s)
{
	// each case evaluates if the square's sides will match
	// those of the squares already on the board
	switch (numSquares)
	{
	case 0:
		return true;
	case 1:
		return (grid[1][1].GetRight() + s.GetLeft() == 0);
	case 2:
		return (grid[1][2].GetBottom() + s.GetTop() == 0);
	case 3:
		return (grid[1][1].GetBottom() + s.GetTop() == 0 &&
			grid[2][2].GetLeft() + s.GetRight() == 0);
	case 4:
		return (grid[2][1].GetLeft() + s.GetRight() == 0);
	case 5:
		return (grid[1][1].GetLeft() + s.GetRight() == 0 &&
			grid[2][0].GetTop() + s.GetBottom() == 0);
	case 6:
		return (grid[1][0].GetTop() + s.GetBottom() == 0);
	case 7:
		return (grid[1][1].GetTop() + s.GetBottom() == 0 &&
			grid[0][0].GetRight() + s.GetLeft() == 0);
	case 8:
		return (grid[0][1].GetRight() + s.GetLeft() == 0 &&
			grid[1][2].GetTop() + s.GetBottom() == 0);
	}
}

// adds a square at the next position and also adds the char
// corresponding to that square to the SquareNames array
void Board::AddSquare(Square & s, int index)
{
	switch (numSquares)
	{
	case 0:
		grid[1][1] = s;
		SquareNames[1][1] = index + 65;
		break;
	case 1:
		grid[1][2] = s;
		SquareNames[1][2] = index + 65;
		break;
	case 2:
		grid[2][2] = s;
		SquareNames[2][2] = index + 65;
		break;
	case 3:
		grid[2][1] = s;
		SquareNames[2][1] = index + 65;
		break;
	case 4:
		grid[2][0] = s;
		SquareNames[2][0] = index + 65;
		break;
	case 5:
		grid[1][0] = s;
		SquareNames[1][0] = index + 65;
		break;
	case 6:
		grid[0][0] = s;
		SquareNames[0][0] = index + 65;
		break;
	case 7:
		grid[0][1] = s;
		SquareNames[0][1] = index + 65;
		break;
	case 8:
		grid[0][2] = s;
		SquareNames[0][2] = index + 65;
	}

	numSquares += 1;
	return;
}

// removes a square simply by reducing numSquares by 1, which
// will cause the next add to overwrite
void Board::RemoveSquare()
{
	numSquares--;
	return;
}

// display the characters corresponding to the squares followed
// by the number of times the square was rotated
// These value-pairs are at their respective positions on the board
void Board::Display()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << SquareNames[i][j] << grid[i][j].GetRotations() << " ";
		}

		cout << endl;
	}

	cin.get();
}