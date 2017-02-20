#ifndef HEAPSORT_H
#define HEAPSORT_H

void bubbleDown(int i, int * array, int size)
{
	int child, index, copy;

	child = i * 2 + 1;
	index = i;

	while (child < size)
	{
		// change the child to swap if the right child is greater
		if (child + 1 < size && array[child + 1] > array[child])
			child++;

		// switch the child with the parent
		if (array[index] < array[child]) {
			copy = array[child];
			array[child] = array[index];
			array[index] = copy;
		}

		index = child;
		child = index * 2 + 1;
	}
}

double heapsort(int * array, int size)
{
	double start = clock();
	int i, copy;

	// bubble down all parent nodes to create heap
	for (i = size / 2; i >= 0; i--)
		bubbleDown(i, array, size);

	// swap first with the last and bubble the first down
	for (i = size - 1; i >= 0; i--)
	{
		copy = array[0];
		array[0] = array[i];
		array[i] = copy;

		bubbleDown(0, array, i);
	}

	double end = clock();
	double total = (end - start) / CLOCKS_PER_SEC;
	return total;
}

#endif

// source: Dr. Carroll's video