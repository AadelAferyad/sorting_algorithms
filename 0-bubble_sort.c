#include "sort.h"

/**
 * bubble_sort - simple sorting algorithm that
 * repeatedly steps through the list,
 * compares adjacent elements,
 * and swaps them if they are in the wrong order.
 *
 * @array: array of integer so sort.
 * @size: size of the array.
 *
*/

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	int temp = 0, count = 0;

	while (array && i < size)
	{
		count = 0;
		for (j = 0, k = 1; k < size; j++, k++)
		{
			if (array[j] > array[k])
			{
				temp = array[j];
				array[j] = array[k];
				array[k] = temp;
				count = 1;
				print_array(array, size);
			}
		}
		if (!count)
			break;
		i++;
	}
}
