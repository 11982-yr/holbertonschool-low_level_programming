#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y.
 *
 * @x: the value to be raised.
 * @y: the power value.
 *
 * Return: if y > 0 - return the value,
 * if y < 0 - return -1
 */

int _pow_recursion(int x, int y)
{
	int result = x;

	if (y < 0)
		return (-1);

	else if
		(y == 0)
			return (1);

	result *= _pow_recursion(x, y - 1);
	return (result);
}
