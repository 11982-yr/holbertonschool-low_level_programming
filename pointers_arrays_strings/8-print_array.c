#include "main.h"
#include <stdio.h>

/**
 * print_array - prints elements of an array of integers.
 * @n: the number of elements of the array to be printed.
 * @a: the array of integers.
 */

void print_array(int *a, int n)
{
	int index;

	for (index = 0; index < n; index++)
	{
		printf("%d", a[index]);

		if (index == n - 1)
			continue;

			printf(", ");
	}
	printf("\n");
}
