#ifndef POOL_H
#define POOL_H

class Pool
{
public:
	Pool();
	int NextUnusedIndex(int);
	Square GetNextUnused(int);
	void MarkUsed(int);
	void MarkUnused(int);

private:
	Square PoolOfSquares[9];
	bool used[9];
};

#endif
