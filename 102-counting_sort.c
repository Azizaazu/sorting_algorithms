#include "sort.h"

/**
 * counting_sort - sorts an array of integers
 * @array: pointer to array
 * @size: size of the array
 *
 **/

void counting_sort(int *array, size_t size)
{
	int a, j, *ct_array, *ax;
	size_t i;

	if (!array || size < 2)
		return;
	a = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > a)
			a = array[i];
	}
	ct_array = calloc((a + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		ct_array[array[i]]++;
	}
	for (j = 1; j < a; j++)
	{
		ct_array[j + 1] += ct_array[j];
	}
	print_array(ct_array, a + 1);
	ax = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		ct_array[array[i]]--;
		ax[ct_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = ax[i];
	}
	free(ax);
	free(ct_array);
}
