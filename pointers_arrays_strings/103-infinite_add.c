#include "main.h"

/**
 * infintie_add - adds two numbers.
 *
 * @n1: the first number to be added.
 * @n2: the second number to be added.
 * @r: the buffer that will be used to store the result.
 * @size_r: the buffer size.
 *
 * Return: if r can store the num - positive result.
 * if r cannot store the num - 0.
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, sum, carry = 0;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;

	if (i + 2 > size_r || j + 2 > size_r)
		return (0);

	r[size_r - 1] = '\0';
	k = size_r - 2;

	i--; j--;
	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		r[k--] = (sum % 10) + '0';
		carry = sum / 10;
	}
	k++;

	if (k < 0)
		return (0);

	return (r + k);
}
