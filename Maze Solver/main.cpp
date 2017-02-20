#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

const int MAX_SIZE = 100;

void Permutations(string, const int &, int);
bool Prime(const int &, int);
void SolveMaze(char[][MAX_SIZE], int, int, const int &, const int &, bool &,
	char);


int main()
{
	string inStr;			// input string for permutations
	int inStrLength;

	int num;				// number to test for prime
	
	int rows, columns;					// rows, columns of input maze
	int startRow, startColumn;			// starting row, column
	int endRow, endColumn;				// goal row, column
	char maze[MAX_SIZE][MAX_SIZE];		// character array for maze
	string oneRow;						// store one row of maze
	bool solved = false;				// keeps path, skips code

	int i, j;
	int numTest;			// number of strings/numbers to test
	
	ifstream myIn;
	myIn.open("ola3data.txt");

	myIn >> numTest;
	myIn.ignore(numeric_limits<streamsize>::max(), '\n');

	for (i = 0; i < numTest; i++)
	// get string to find permutations, record length, call function
	{
		getline(myIn, inStr);
		inStrLength = inStr.length();
		Permutations(inStr, inStrLength, 0);
		cout << endl << endl;
	}

	cout << endl;
	myIn >> numTest;
	myIn.ignore(numeric_limits<streamsize>::max(), '\n');

	for (i = 0; i < numTest; i++)
	// get number to test prime, call function and display result
	{
		myIn >> num;
		myIn.ignore(numeric_limits<streamsize>::max(), '\n');

		if (Prime(num, num / 2))
			cout << "The number " << num << " is prime.\n\n";
		else
			cout << "The number " << num << " is not prime.\n\n";
	}

	myIn >> rows >> columns;
	myIn.ignore(numeric_limits<streamsize>::max(), '\n');
	myIn >> startRow >> startColumn;
	myIn.ignore(numeric_limits<streamsize>::max(), '\n');
	myIn >> endRow >> endColumn;
	myIn.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\nHere is the maze:\n";

	for (i = 0; i < rows; i++)
	// get a row of the maze, add it, and also display what is read
	{
		getline(myIn, oneRow);

		for (j = 0; j < columns; j++)
		{
			maze[i][j] = oneRow[j];
			cout << maze[i][j];
		}

		cout << endl;
	}

	cout << endl;
	myIn.close();

	SolveMaze(maze, startRow, startColumn, endRow, endColumn, solved, 'n');

	if (solved)
	// if the function solved the maze, display the solution
	// the function modifies the original maze
	{
		cout << "The maze has a solution:" << endl;

		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < columns; j++)
				cout << maze[i][j];

			cout << endl;
		}
	}

	else
		cout << "The maze does not have a solution.";

	cin.get();
	return 0;
}

void Permutations(string inStr, const int & inStrLength, int start)
{
	int index;

	// base case, no more swapping chars can be done
	if (start == inStrLength)
		cout << inStr << " ";

	else
	{
		// swap the char at start with every other char greater than
		// start and call the function recursively with start + 1 to
		// generate subsequent permutations, then swap them back
		for (index = start; index < inStrLength; index++)
		{
			swap(inStr[start], inStr[index]);
			Permutations(inStr, inStrLength, start + 1);
			swap(inStr[start], inStr[index]);
		}
	}
}

bool Prime(const int & num, int divisor)
{
	// if the function makes it this far, num must be prime
	// otherwise, the recursive function calls short-circuit
	if (divisor == 1)
		return true;

	else
	{
		// num is divisible by a number besides itself and one
		if (num % divisor == 0)
			return false;

		// evaluate the number with divisor  being one less
		else
			return Prime(num, divisor - 1);
	}
}

void SolveMaze(char maze[][MAX_SIZE], int startRow, int startColumn,
	const int & endRow, const int & endColumn, bool & solved, char previous)
{
	// recursive calls skip most of code when the solution is found
	if (!solved)
	{
		// base case, the goal row and column has been reached
		if (startRow == endRow && startColumn == endColumn)
		{
			// mark the position for solution, set solved to true
			maze[startRow][startColumn] = 'O';
			solved = true;
			return;
		}

		else
		{
			// if one of the boundaries has been hit, return
			if (maze[startRow][startColumn] == '#')
				return;

			else
			{
				// mark the position for solution, even though it may not be
				maze[startRow][startColumn] = 'O';

				// call the function recursively with different values depending on
				// the direction of the last move, u = up, d = down, l = left, r = right
				// prevents moving back and forth infinitely between two positions
				switch (previous)
				{
				// only for the first call in main, calls function for every direction
				case 'n':
					SolveMaze(maze, startRow + 1, startColumn, endRow, endColumn, solved, 'd');
				
				// call a new function for every direction but down
				case 'u':
					SolveMaze(maze, startRow - 1, startColumn, endRow, endColumn, solved, 'u');
					SolveMaze(maze, startRow, startColumn - 1, endRow, endColumn, solved, 'l');
					SolveMaze(maze, startRow, startColumn + 1, endRow, endColumn, solved, 'r');
					break;
				
				// call a new function for every direction but up
				case 'd':
					SolveMaze(maze, startRow + 1, startColumn, endRow, endColumn, solved, 'd');
					SolveMaze(maze, startRow, startColumn - 1, endRow, endColumn, solved, 'l');
					SolveMaze(maze, startRow, startColumn + 1, endRow, endColumn, solved, 'r');
					break;
				
				// call a new function for every direction but right
				case 'l':
					SolveMaze(maze, startRow - 1, startColumn, endRow, endColumn, solved, 'u');
					SolveMaze(maze, startRow + 1, startColumn, endRow, endColumn, solved, 'd');
					SolveMaze(maze, startRow, startColumn - 1, endRow, endColumn, solved, 'l');
					break;
				
				// call a new function for every direction but left
				case 'r':
					SolveMaze(maze, startRow - 1, startColumn, endRow, endColumn, solved, 'u');
					SolveMaze(maze, startRow + 1, startColumn, endRow, endColumn, solved, 'd');
					SolveMaze(maze, startRow, startColumn + 1, endRow, endColumn, solved, 'r');
				}

				// if none of the function calls solved the maze, change the
				// character back because this path doesn't lead to a solution
				if (!solved)
					maze[startRow][startColumn] = '.';

				return;
			}
		}
	}

	// solution already found, no need to evaluate anything
	else
		return;
}