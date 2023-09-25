#include "sort.h"


/**
 * swap_items - Swaps items in an array.
 *
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */

void swap_items(int *array, size_t l, size_t r)
{
	int temp;

	if (array != NULL)
	{
		temp = array[l];
		array[l] = array[r];
		array[r] = temp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub array
 *
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */

void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t d, i;
	int pvt;

	if ((low >= high) || (array == NULL))
		return;
	pvt = array[high];
	d = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pvt)
		{
			if (d != i)
			{
				swap_items(array, d, i);
				print_array(array, size);
			}
			d++;
		}
	}
	if (d != high)
	{
		swap_items(array, d, high);
		print_array(array, size);
	}
	if (d - low > 1)
		quick_sort_range_lomuto(array, low, d - 1, size);
	if (high - d > 1)
		quick_sort_range_lomuto(array, d + 1, high, size);
}

/**
 * quick_sort - Sorts an array
 *
 * @array: The array to sort.
 * @size: The length of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
