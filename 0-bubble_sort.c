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

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swap array[j] and array[j + 1] */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* print array after each swap */
				print_array(array, size);
			}
		}
	}
}
