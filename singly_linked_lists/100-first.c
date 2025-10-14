#include <stdio.h>

/**
 * hare - prints a string before main is executed.
 *
 */

void __attribute__((constructor)) hare(void)
{
	printf("You're beat! and yet, you must allow,"
			"\nI bore my house upon my back!\n");
}
