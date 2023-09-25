#include "sort.h"
#include <stdio.h>

/**
 * _swap - swap two value
 * @array: array for swap
 * @i: First index
 * @j: Second index
 *
 * Return: Nothing
 */

void _swap(int *array, int i, int j)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * shell_sort - sort the list
 * @array: array
 * @size: Size
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t hl = 0,  i, j;

	if (size < 2)
		return;

	while (hl <= size / 3)
		hl = hl * 3 + 1;

	while (hl >= 1)
	{
		for (i = hl; i < size; i++)
			for (j = i; j >= hl && array[j] < array[j - hl]; j -= hl)
				_swap(array, j, j - hl);
		hl /= 3;
		print_array(array, size);
	}
}
