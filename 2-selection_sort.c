#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 *
 * @array: a pointer to the array of integers to be sorted.
 * @size: the size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int *address;
	bool swapped = false;

	for (i = 0; i < size - 1; i++)
	{
		temp = array[i];
		address = &array[i];
		swapped = false;

		for (j = i + 1; j < size; j++)
		{
			if (temp > array[j])
			{
				swapped = true;
				temp = array[j];
				address = &array[j];
			}
		}

		if (swapped)
		{
			*address = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
