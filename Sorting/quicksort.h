#ifndef QUICKSORT_H
#define QUICKSORT_H

void quickRecursion(int * array, int first, int last)
{
	int i = first;
	int j = last;
	int tmp;

	// pivot around middle element
	int pivot = array[(first + last) / 2];

	// loop until i and j cross
	while (i <= j) {
		while (array[i] < pivot)	// find index of first value greater than pivot
			i++;
		while (array[j] > pivot)	// find index of first value less than pivot
			j--;
		if (i <= j) {				// swap the two values if on wrong side of pivot
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	}

	// recursive calls for each half
	if (first < j)
		quickRecursion(array, first, j);
	if (i < last)
		quickRecursion(array, i, last);
}

double quicksort(int * array, int size)
{
	double start = clock();

	int first = 0;
	int last = size - 1;

	quickRecursion(array, first, last);

	double end = clock();
	double total = (end - start) / CLOCKS_PER_SEC;
	return total;
}

#endif

// source: explanation and code from
// http://www.algolist.net/Algorithms/Sorting/Quicksort