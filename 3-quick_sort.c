#include "sort.h"

/**
 * partition - Lomuto partition scheme.
 *
 * @start: the start of the array or the sub array.
 * @end: the end of the array or sub array.
 * @array: the main array.
 * @size: the size of the main array.
 *
 * Return: return the index of the sorted value.
*/
int partition(int start, int end, int *array, int size)
{
	int pivot = array[end], tmp;
	int i = start - 1, j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	if (array[i + 1] > array[end])
	{
		i++;
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i);
}
/**
 * quickSort -  is a divide-and-conquer algorithm.
 * It works by selecting a 'pivot'
 * element from the array and partitioning
 * the other elements into two sub-arrays
 *
 * @start: the start of the array or the sub array.
 * @end: the end of the array or sub array.
 * @array: the main array.
 * @size: the size of the main array.
*/
void quickSort(int start, int end, int *array, int size)
{
	int pivot_offset;

	if (end > start)
	{
		pivot_offset = partition(start, end, array, size);
		quickSort(start, pivot_offset - 1, array, size);
		quickSort(pivot_offset + 1, end, array, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: the unsorted array.
 * @size: size of the array.
 *
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(0, size - 1, array, size);
}
