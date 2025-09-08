#include "main.h"

/**
 * check_prime - helper function to check if n is divisible.
 * @n: number to check
 * @i: current divisor being tested.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int check_prime(int n, int i)
{
	if (i * i > n)
		return (1);

	else if (n % i == 0)
		return (0);
	return (check_prime(n, i + 1));
}


/**
 * is_prime_number - returns prime number.
 *
 * @n: the number to be returned.
 *
 * Return: 1 if the input is prime number,
 * otherwise return 0.
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (check_prime(n, 2));
}
