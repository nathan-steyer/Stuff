#include "square.h"
using namespace std;

// default constructor
Square::Square()
{
	top = 0;
	right = 0;
	bottom = 0;
	left = 0;
	rotations = 0;
}

// value constructor
Square::Square(int t, int r, int b, int l)
{
	top = t;
	right = r;
	bottom = b;
	left = l;
	rotations = 0;
}

// value "getters"
int Square::GetTop() { return top; }
int Square::GetRight() { return right; }
int Square::GetBottom() { return bottom; }
int Square::GetLeft() { return left; }
int Square::GetRotations() { return rotations; }

// rotate a square object one position clockwise
void Square::Rotate()
{
	int tmp = top;
	top = left;
	left = bottom;
	bottom = right;
	right = tmp;

	// keep the rotations data member between 0 and 3
	rotations = (rotations + 1) % 4;

	return;
}