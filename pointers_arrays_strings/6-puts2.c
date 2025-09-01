#include "main.h"

/**
 * puts2 - prints every other character of a string.
 * @str: the character of the string to be printed.
 */

void puts2(char *str)
{
	int len = 0, index = 0;

	while (str[index++])
		len++;

	for (index = len - 1; index < len; index += 2)
		_putchar(str[index]);

	_putchar('\n');
}
