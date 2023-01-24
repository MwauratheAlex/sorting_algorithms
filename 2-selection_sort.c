#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: array to sort
 *
 * @size: size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j = 0;
	int buffer;
	int smallest;
	int smallest_idx = 0;

	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				smallest_idx = j;
			}
		}
		buffer = array[i];
		array[i] = smallest;
		array[smallest_idx] = buffer;
		print_array(array, size);
	}
}
