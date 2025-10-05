#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 *
 * @h: the head of the list.
 *
 * Return: the number of nodes. if str == NULL, print [0] (nil)
 */

size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d], %s\n", h->len, h->str);

		nodes++;
		h = h->next;
	}

	return (nodes);
}
