#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a linked list.
 *
 * @head: the head of the node.
 * @index: the index of the node.
 *
 * Return: 1 if succeeded, -1 if failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;

	if (head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
	}

	if (tmp == *head)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->prev->next = tmp->prev;
	}
	free(tmp);
	return (1);
}
