#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 *
 * @s: the string to be returned.
 *
 * Return: the length of the string.
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - helper function.
 *
 * @s: the string.
 * @start: starting index.
 * @end: ending index.
 *
 * Return: 1 if palindrome, 0 otherwise.
 */

int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - determines if a string is a palindrome.
 *
 * @s: the string to be determined.
 *
 * Return: 1 if string is a palindrome,
 * 0 if not.
 */

int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);
	if (len <= 1)
		return (1);
	return (check_palindrome(s, 0, len - 1));
}
