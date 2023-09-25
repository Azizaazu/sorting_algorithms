#include "sort.h"

#include <stdio.h>


/**
 * selection_sort - sorts an array of integers
 * @array: array
 * @size: size
 * Return: void
 *
 */


void selection_sort(int *array, size_t size)
{
        size_t x, stp, min_index;
        int tmp;

        for (stp = 0; stp < size - 1; stp++)
        {
                min_index = stp;
                for (x = stp + 1; x < size; x++)
                {
                        if (array[x] < array[min_index])
                                min_index = x;
                }

                if (min_index != stp)
                {
                        tmp = array[stp];
                        array[stp] = array[min_index];
                        array[min_index] = tmp;
                        print_array(array, size);
                }
	}
}
