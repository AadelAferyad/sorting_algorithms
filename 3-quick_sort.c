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
int partition(size_t start, size_t end, int *array, size_t size)
{
	int pivot = 0, tmp;
	size_t i = start - 1, j;
	/*19, 48, 99, 71, 13, 52, 96, 73, 86, 7*/
	/*i is searching for elements that are greater then pivot*/
	/*j is searching for elements that are smaller then pivot*/
	/*pivot = [4] 2 3 20 30 44 1 12 29 5 9*/
				/*2 3 1 4 44 20 12 29 5 9 30*/
				/*i i i	i*/
	if (end <= 0)
		return (0);
	pivot = array[end];
	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[end];
	array[end] = tmp;
	print_array(array, size);
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
void quickSort(size_t start, size_t end, int *array, size_t size)
{
	size_t pivot_offset = 0;

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
	if (!array || size <= 0)
		return;
	quickSort(0, size - 1, array, size);
}
