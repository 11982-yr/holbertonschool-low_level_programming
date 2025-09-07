#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 *
 * @s: the first string to be searched.
 * @accept: the second string to be searched.
 *
 * Return: a pointer to the byte in s,
 * the matches one of the bytes in accept,
 * or NULL if no byte is found.
 */

char *_strpbrk(char *s, char *accept)
{
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
				return (s);
		}
		s++;
	}
	return ('\0');
}
