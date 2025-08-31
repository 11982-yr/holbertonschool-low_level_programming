#include "main.h"

/**
 * print_triangle - prints a triangle.
 * @size: the size of the triangle.
 */

void print_triangle(int size)
{
	int hash, index;

	for (hash = 1; hash <= size; hash++)
	{
		for (index = size - hash; index > 0; index--)
			_putchar(' ');
		{
			for (index = 0; index < hash; index++)
				_putchar('#');

			if (hash == size)
				continue;
			_putchar('\n');
		}
	}
	_putchar('\n');
}
