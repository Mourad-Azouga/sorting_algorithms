#include "sort.h"
/**
 * bubble_sort - Sorts an array
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, size2 = size;
	int temp;
	int done = 0;

	while (done == 0)
	{
		done = 1;
		for (i = 0; i < size2 - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				done = 0;
			}
		}
		size2--;
	}
}
