#include "main.h"

/**
 * _strchr - locates a character in a string.
 *
 * @s: the string.
 * @c: the character to be located.
 *
 * Return: a pointer to c in s, or NULL.
 */

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index] >= '\0'; index++)
	{
		if (s[index] == c)
			return (s + index);
	}
	return ('\0');
}
