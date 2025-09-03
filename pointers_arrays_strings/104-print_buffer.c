#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer.
 *
 * @b: a pointer to the buffer.
 * @size: contains the bytes of the buffer.
 */

void print_buffer(char *b, int size)
{
	int byte, index;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (byte = 0; byte < size; byte += 10)
	{
		printf("%08x: ", byte);

		for (index = 0; index < 10; index++)
		{
			if ((index + byte) >= size)
				printf("  ");

			else
				printf("%02x", *(b + index + byte));

			if ((index % 2) != 0 && index != 0)
				printf(" ");
		}

		for (index = 0; index < 10; index++)
		{
			if ((index + byte) >= size)
				break;

			else if (*(b + index + byte) >= 32 &&
					*(b + index + byte) <= 126)
				printf("%c", *(b + index + byte));
			else
				printf(".");
		}
		printf("\n");
	}
}
