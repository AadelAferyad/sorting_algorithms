#include "sort.h"


int partition(size_t l, size_t h, int *array, size_t size)
{
	int pivot = array[h], tmp;
	size_t i = l, j = h;
	/*i is searching for elements that are greater then pivot
	  j is searching for elements that are smaller then pivot
	  pivot = [4] 2 3 20 30 44 1 12 29 5 4*/
	  while (i < j)
	  {
		do
		{
			i++;
		}
	  	while (array[i] <= pivot);
		do
		{
			j--;
		}
		while(array[j] >= pivot);
		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	  }
	tmp = array[h];
	array[h] = array[j];
	array[j] = tmp;
	print_array(array, size);
	return (j);
}
void quickSort(size_t l, size_t h, int *array, size_t size)
{
	size_t j = 0;
	if (l < h)
	{
		j = partition(l, h, array, size);
		quickSort(l, j, array, size);
		quickSort(j + 1, h, array, size);
	}
}
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 0)
		return;
	quickSort(0, size - 1, array, size);
}
