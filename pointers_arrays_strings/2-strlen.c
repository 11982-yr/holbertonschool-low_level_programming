#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @str: the string to get the length of.
 *
 * Return: the length of @str.
 */

int _strlen(char *s)
{
		int length = 0;

		while (*s != '\0')
		{
			length++;
			s++;
		}
		return (length);
}
