#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
	* _is_digit - checks if a string contains only digits
	* @s: string
	* Return: 1 if only digits, 0 otherwise
	*/
int _is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
	if (s[i] < '0' || s[i] > '9')
	return (0);
	i++;
	}
	return (1);
}

/**
	* _strlen - returns string length
	* @s: string
	* Return: length
	*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	i++;
	return (i);
}

/**
	* print_number - prints a number stored in an int array
	* @res: array of digits
	* @len: length of array
	*/
void print_number(int *res, int len)
{
	int i = 0;

	while (i < len && res[i] == 0)
	i++;

	if (i == len)
	_putchar('0');
	else
	for (; i < len; i++)
	_putchar(res[i] + '0');

	_putchar('\n');
}

/**
* multiply - multiplies two numeric strings
* @n1: first number
* @n2: second number
* @len1: length of n1
* @len2: length of n2
* Return: pointer to array containing the product
*/
int *multiply(char *n1, char *n2, int len1, int len2)
{
	int *res, i, j;
	int len = len1 + len2;

	res = malloc(sizeof(int) * len);
	if (!res)
	exit(98);

	for (i = 0; i < len; i++)
	res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
	for (j = len2 - 1; j >= 0; j--)
	{
	int mul = (n1[i] - '0') * (n2[j] - '0');
	int pos1 = i + j;
	int pos2 = i + j + 1;
	int sum = mul + res[pos2];

	res[pos2] = sum % 10;
	res[pos1] += sum / 10;
	}
	}

	return (res);
}

/**
* main - multiplies two positive numbers
* @argc: argument count
* @argv: argument vector
* Return: 0
*/
int main(int argc, char *argv[])
{
	char *n1, *n2;
	int len1, len2, *res;

	if (argc != 3)
	{
	printf("Error\n");
	exit(98);
	}

	n1 = argv[1];
	n2 = argv[2];

	if (!_is_digit(n1) || !_is_digit(n2))
	{
	printf("Error\n");
	exit(98);
	}

	len1 = _strlen(n1);
	len2 = _strlen(n2);

	res = multiply(n1, n2, len1, len2);

	print_number(res, len1 + len2);

	free(res);
	return (0);
}
