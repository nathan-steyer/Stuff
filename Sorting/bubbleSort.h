#ifndef BUBBLESORT_H
#define BUBBLESORT_H

double bubbleSort(int * array, int size)
{
	double start = clock();
	int i, j, copy;

	// outer loop for limiting inner loop
	for (i = size - 1; i > 0; i--)
	{
		// bubble up values in each pair
		for (j = 0; j < i; j++)
			if (array[j] > array[j + 1]) {
				copy = array[j];
				array[j] = array[j + 1];
				array[j + 1] = copy;
			}
	}

	double end = clock();
	double total = (end - start) / CLOCKS_PER_SEC;
	return total;
}

#endif

// source: Dr. Carroll's video
