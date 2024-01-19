#include "sort.h"

/**
 * selection_sort - a simple sorting algorithm that works
 * by repeatedly finding the minimum element from the unsorted
 * part of the array and putting it at the beginning.
 *
 * @array: array of integer so sort.
 * @size: size of the array.
 *
*/

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, index = 0;
	int small = 0, is_sorted = 0, tmp = 0;

	while (i < size && array)
	{
		is_sorted = 0;
		small = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (small > array[j])
			{
				small = array[j];
				index = j;
				is_sorted = 1;
			}
		}
		if (is_sorted)
		{
			tmp = array[index];
			array[index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
