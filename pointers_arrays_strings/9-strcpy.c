#include "main.h"

/**
 * _strcpy - copies the string pointed to by src.
 * @dest: the desination of the string.
 * @src: the source of the string.
 *
 * Return: a pointer to the destination string @dest
 */

char *_strcpy(char *dest, char *src)
{
	int index = 0;

	while (src[index])
	{
		dest[index] = src[index];
			index++;
	}

	dest[index] = '\0';
	return (dest);
}
