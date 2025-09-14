#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes it.
 *
 * @size: the size of the array.
 * @c: creates an array of chars.
 *
 *
 * Return: a pointer to the array or NULL if size = 0.
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int index;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		array[index] = c;

	return (array);
}
