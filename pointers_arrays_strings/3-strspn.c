#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 *
 * @s: the substring to be checked.
 * @accept: the prefix to be measured.
 *
 * Return: the number of bytes in s,
 * which consists of bytes from accept.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, found;

	while (*s)
	{
		found = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				count++;
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		s++;
	}
	return (count);
}
