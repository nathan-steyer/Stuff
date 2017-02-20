#ifndef MERGESORT_H
#define MERGESORT_H

void mergeRecursion(int * array, int first, int last, int * mergedArray)
{
	if (first < last)
	{
		int mid = (first + last) / 2;

		// recursive calls for each half
		mergeRecursion(array, first, mid, mergedArray);
		mergeRecursion(array, mid + 1, last, mergedArray);

		// merge the two halves
		int leftHalf = first;
		int rightHalf = mid + 1;
		int index = first;

		// while the indices are not outside of their halves
		while (leftHalf <= mid && rightHalf <= last)
		{
			// add left value if less than right
			if (array[leftHalf] < array[rightHalf]) {
				mergedArray[index] = array[leftHalf];
				leftHalf++;
			}

			// add right value
			else {
				mergedArray[index] = array[rightHalf];
				rightHalf++;
			}

			index++;
		}

		// add the rest of the values from left half
		while (leftHalf <= mid)
		{
			mergedArray[index] = array[leftHalf];
			leftHalf++;
			index++;
		}

		// add the rest of the values from the right half
		while (rightHalf <= last)
		{
			mergedArray[index] = array[rightHalf];
			rightHalf++;
			index++;
		}

		// copy the temporary array to the original one
		for (int i = first; i < index; i++)
			array[i] = mergedArray[i];
	}
}

double mergesort(int * array, int size)
{	
	double start = clock();

	int first = 0;
	int last = size - 1;

	// create temporary array for storing merged partial arrays
	int * mergedArray = new int[size];

	mergeRecursion(array, first, last, mergedArray);

	delete[] mergedArray;
	
	double end = clock();
	double total = (end - start) / CLOCKS_PER_SEC;
	return total;
}

#endif

// source: Dr. Carroll's video for pseudo code
// mostly my own work with some help from
// http://quiz.geeksforgeeks.org/merge-sort/