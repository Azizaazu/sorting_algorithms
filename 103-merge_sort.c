#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copies data
 *
 * @src: source
 * @dst: destination
 * @size: size
 * Return: No Return
 *
 */

void copy(int *src, int *dst, int size)
{
	int x;

	for (x = 0; x < size; x++)
		dst[x] = src[x];
}

/**
 * merge - merges two sets of data
 * @array: first set of data
 * @buff: second set of data
 * @minL: lower range of first set of data
 * @maxL: upper range of first set of data
 * @minR: lower range of second set of data
 * @maxR: upper range of second set of data
 *
 * Return: No Return
 *
 */

void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int a = minL, b = minR, c = minL;

	while (a <= maxL || b <= maxR)

		if (a <= maxL && b <= maxR)
			if (buff[a] <= buff[b])
				array[c] = buff[a], c++, a++;
			else
				array[c] = buff[b], c++, b++;

		else if (a > maxL && b <= maxR)
			array[c] = buff[b], c++, b++;
		else
			array[c] = buff[a], c++, a++;
}

/**
 * printcheck - prints an array in range
 *
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 * Return: No Return
 *
 */

void printcheck(int *array, int r1, int r2)
{
	int a;

	for (a = r1; a <= r2; a++)
	{
		if (a > r1)
			printf(", ");
		printf("%d", array[a]);
	}
	printf("\n");
}

/**
 * split - recursive function to split data
 *
 * @array: array
 * @buff: auxiliary array
 * @min: min range
 * @max: max range
 * @size: size
 *
 * Return: No Return
 *
 */

void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}

/**
 * merge_sort - sorts an array of integers
 *
 * @array: array
 * @size: size of data
 * Return: No Return
 *
 */

void merge_sort(int *array, size_t size)
{
	int *bf;

	if (size < 2)
		return;

	bf = malloc(sizeof(int) * size);
	if (bf == NULL)
		return;

	copy(array, bf, size);

	split(array, bf, 0, size - 1, size);

	free(bf);
}
