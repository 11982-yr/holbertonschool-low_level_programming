#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int find_len(char *str);
char *create_xarray(int size);
char *iterate_zeroes(char *str);
void get_prod(char *prod, char *mult, int digit, int zeroes);
void add_nums(char *final_prod, char *next_prod, int next_len);

/**
 * find_len - find the length of the string.
 * @str: the string to be searched.
 *
 * Return: the length of the string.
 */

int find_len(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * create_xarray - allocates memory for a character array.
 * @size: the input size of the array.
 *
 * Return: the created array.
 */

char *create_xarray(int size)
{
	char *array;
	int index;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		exit(98);

	for (index = 0; index < (size - 1); index++)
		array[index] = 'x';

	array[index] = '\0';

	return (array);
}

/**
 * iterate_zeroes - takes a string and returns a pointer.
 *
 * @str: the string to be taken.
 *
 * Return: a pointer to the null-terminator.
 */

char *iterate_zeroes(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}

/**
 * get_digit - converts a single character.
 *
 * @c: the character to be converted.
 *
 * Return: the integer value of the digit.
 */
int get_digit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}
	return (digit);
}

/**
 * get_prod - performs the multiplication of a number string.
 *
 * @prod: the result stored in a character array.
 * @mult: the multiplication of a number.
 * @digit: a single digit.
 * @zeroes: trailing zeroes.
 *
 * Return: a string stored in reverse order.
 */

void get_prod(char *prod, char *mult, int digit, int zeroes)
{
	int mult_len, num, tens = 0;

	mult_len = find_len(mult) - 1;
	mult += mult_len;

	while (*prod)
	{
		*prod = 'x';
		prod++;
	}

	prod--;

	while (zeroes--)
	{
		*prod = '0';
		prod--;
	}

	for (; mult_len >= 0; mult_len--, mult--, prod--)
	{
		if (*mult < '0' || *mult > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*mult - '0') * digit;
		num += tens;
		*prod = (num % 10) + '0';
		tens = num / 10;
	}
	if (tens)
	{
		*prod = (tens % 10) + '0';
	}
}

/**
 * add_nums - takes two numbers represented as character arrays and adds them.
 *
 * @final_prod: array representing the first number.
 * @next_prod: array representing the seocnd number.
 * @next_len: length of the next_prod number.
 */

void add_nums(char *final_prod, char *next_prod, int next_len)
{
	int num, tens = 0;

	while (*(final_prod) != '\0')
		final_prod++;
	final_prod--;

	while (*(next_prod) != '\0')
		next_prod++;
	next_prod--;

	while (next_len-- >= 0 && *next_prod != 'x')
	{
		num = (*final_prod - '0') + (*next_prod - '0') + tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;

		final_prod--;
		next_prod--;
	}

	while (tens && *final_prod != 'x')
	{
		num = (*final_prod - '0') + tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;
		final_prod--;
	}

	if (tens)
		*final_prod = (tens % 10) + '0';
}

/**
 * main - multiplies two positive numbers.
 *
 * @argc: argument count.
 * @argv: argument values.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *final_prod, *next_prod;
	int size, index, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = iterate_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = iterate_zeroes(argv[2]);

	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = find_len(argv[1]) + find_len(argv[2]);
	final_prod = create_xarray(size + 1);
	next_prod = create_xarray(size + 1);

	for (index = find_len(argv[2]) - 1; index >= 0; index--)
	{
		digit = get_digit(*(argv[2] + index));
		get_prod(next_prod, argv[1], digit, zeroes++);
		add_nums(final_prod, next_prod, size - 1);
	}

	for (index = 0; final_prod[index]; index++)
	{
		if (final_prod[index] != 'x')
			putchar(final_prod[index]);
	}
	putchar('\n');

	free(next_prod);
	free(final_prod);
	return (0);
}
