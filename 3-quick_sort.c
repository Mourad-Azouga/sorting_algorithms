#include "sort.h"

int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * hoare_partition - uses the hoare method to make magic
 * @array: The array
 * @size: The size of the array
 * @left: The starting index
 * @right: The ending index 
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[left];
	for (above = left, below = right; ; )
	{
		while (array[above] < pivot)
			above++;
		while (array[below] > pivot)
			below--;

		if (above < below)
		{
			int tmp = array[above];
			array[above] = array[below];
			array[below] = tmp;

			print_array(array, size);
		}
		else
		{
			return below;
		}
	}
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: the array
 * @size: The size of the array
 * @left: The starting index
 * @right: The ending index
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right > left)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part);
		hoare_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts an array
 * @array: the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
