#include <fstream>
#include "square.h"
#include "pool.h"
using namespace std;

// construct pool object with data file
Pool::Pool()
{
	int t, r, b, l;
	
	ifstream myIn;
	myIn.open("ola4data.txt");

	for (int i = 0; i < 9; i++)
	{
		myIn.ignore();
		myIn >> t >> r >> b >> l;
		Square s(t, r, b, l);
		PoolOfSquares[i] = s;		// add square to pool
		used[i] = false;			// initialize used array value to false
		myIn.ignore();
	}

	myIn.close();
}

// returns the index of the next square that hasn't been used
int Pool::NextUnusedIndex(int start)
{
	for (int i = start; i < 9; i++)
	{
		if (used[i] == false)
			return i;
	}
}

// returns the square at the index passed
Square Pool::GetNextUnused(int i)
{
	return PoolOfSquares[i];
}

// marks the square at the index passed as used
void Pool::MarkUsed(int i)
{
	used[i] = true;
	return;
}

// marks the square at the index passed as unused
void Pool::MarkUnused(int i)
{
	used[i] = false;
	return;
}