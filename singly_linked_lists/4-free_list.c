#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list.
 *
 * @head: the head of the list.
 *
 * Description: frees all nodes of a linked list_t list,
 * including the strings in each node.
 */

void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
