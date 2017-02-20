#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
	Square();
	Square(int, int, int, int);
	int GetTop();
	int GetRight();
	int GetBottom();
	int GetLeft();
	int GetRotations();
	void Rotate();

private:
	int top;
	int right;
	int bottom;
	int left;
	int rotations;
};

#endif