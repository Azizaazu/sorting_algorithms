#include "sort.h"

/**
 *swap - positions of 2 elements into an array
 *@array: array
 *@item1: array element
 *@item2: array element
 */

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 *hoare_partition - hoare partition
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *
 *Return: return position
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 *qs - qucksort algorithm
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 *
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t post = 0;

	if (first < last)
	{
		post = hoare_partition(array, first, last, size);
		qs(array, first, post - 1, size);
		qs(array, post, last, size);
	}
}

/**
 *quick_sort_hoare - prepare terrain to quicksort algorithm
 *@array: array
 *@size: array size
 *
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
