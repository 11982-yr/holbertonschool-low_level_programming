#include "main.h"

/**
 * _memcpy - copies memory area.
 *
 * @dest: a pointer to the memory area.
 * @src: the source buffer.
 * @n: the number of bytes.
 *
 * Return: a pointer to dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
