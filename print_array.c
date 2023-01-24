#include "sort.h"
/**
 * print_array - print n elements of an array
 *
 * @array: array to be printed
 *
 * @size: number of elements
 *
 * Return: nothing
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
