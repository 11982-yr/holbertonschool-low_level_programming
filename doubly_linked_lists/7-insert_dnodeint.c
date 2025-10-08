#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 *
 * @h: the head of the list.
 * @idx: the index of the list.
 * @n: the node.
 *
 * Return: the address of the new node, if new node == NULL, return NULL.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp = *h, *new;

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (idx != 1)
	{
		if (tmp == NULL)
			return (NULL);
		tmp = tmp->next;
		idx--;
	}

	if (tmp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = tmp->next;
	new->prev = tmp;

	if (tmp->next != NULL)
		tmp->next->prev = new;
	tmp->next = new;

	return (new);
}
