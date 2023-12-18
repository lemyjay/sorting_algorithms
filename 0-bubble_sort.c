#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: The array containing the elements to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((array[j] > array[j + 1]) && (j + 1 != size))
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
