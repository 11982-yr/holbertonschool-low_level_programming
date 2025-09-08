#include "main.h"

/**
 * wildcmp - compares two strings.
 *
 * @s1: the first string to be compared.
 * @s2: the second string to be compared.
 *
 * Return: 1 if the strings can be identical,
 * 0 otherwise.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)));
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
