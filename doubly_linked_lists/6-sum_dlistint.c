#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data of a dlistint_t.
 * @head: the head of the list.
 *
 * Return: the sum of all the data (n), if list == NULL, return 0.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
