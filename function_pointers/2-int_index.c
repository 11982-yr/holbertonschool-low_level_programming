#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - searches for an integer.
 *
 * @array: the array,
 * @size: the number of elements in the array.
 * @cmp: a pointer to the function to be used.
 *
 * Return: the index of the first element,
 * If no element, return -1, if size <= 0, return -1.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (array == NULL || cmp == NULL)
		return (-1);

	for (index = 0; index < size; index++)
	{
		if (cmp(array[index]) != 0)
			return (index);
	}
	return (-1);
}
