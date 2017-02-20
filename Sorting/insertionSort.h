#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

double insertionSort(int * array, int size)
{
	double start = clock();
	int i, j, copy;

	for (i = 1; i < size; i++)
	{
		copy = array[i];
		j = i;

		// move elements over until element is greater than next
		while (j > 0 && array[j - 1] > copy) {
			array[j] = array[j - 1];
			j--;
		}

		array[j] = copy;	// insert the element
	}

	double end = clock();
	double total = (end - start) / CLOCKS_PER_SEC;
	return total;
}

#endif

// source: Dr. Carroll's video
