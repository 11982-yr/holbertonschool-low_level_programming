#include <stdio.h>
#include <stdlib.h>

/**
 * get_coins - computes minimum number of coins.
 *
 * @cents: amount of money
 *
 * Return: number of coins.
 */
int get_coins(int cents)
{
	int coins = 0;

	while (cents > 0)
	{
		coins++;
		if (cents - 25 >= 0)
		{
			cents -= 25;
			continue;
		}

		if (cents - 10 >= 0)
		{
			cents -= 10;
			continue;
		}

		if (cents - 5 >= 0)
		{
			cents -= 5;
			continue;
		}

		if (cents - 2 >= 0)
		{
			cents -= 2;
			continue;
		}
		cents--;
	}

	return (coins);
}

/**
 * main - check the code.
 * @argc: argument count.
 * @argv: argument values.
 *
 * Return: 0 on success, 1 on error.
 */

int main(int argc, char *argv[])
{
	int cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}
	printf("%d\n", get_coins(cents));
	return (0);
}
