#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array
 *
 * @array: array
 * @size: size array
 * Return: void
 *
 */


void bubble_sort(int *array, size_t size)
{
	size_t x;
	int temp, srtd;

	if (!array || size == 0)
		return;

	do {
		srtd = 1;
		for (x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				srtd = 0;
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				print_array(array, size);
			}
		}

	} while (srtd == 0);
}
