#include "sort.h"

/**
 * selection_sort - Sorts an array of integers
 *
 * @array:    - Pointer to the array of integers.
 * @size:    - Size of the given array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, idx = 0;
	int swp;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[idx])
				idx = j;

		if (idx != i)
		{
			swp = array[i];
			array[i] = array[idx];
			array[idx] = swp;
			print_array(array, size);
		}
	}
}
