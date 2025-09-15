#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc.
 *
 * @nmemb: the number of elements.
 * @size: the byte size.
 *
 * Return: if nmemb or size = 0, the _calloc returns NULL.
 * if malloc fails, then _calloc returns NULL.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem;
	char *filler;
	unsigned int index;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem = malloc(size * nmemb);

	if (mem == NULL)
		return (NULL);

	filler = mem;

	for (index = 0; index < (size * nmemb); index++)
		filler[index] = '\0';

	return (mem);
}
