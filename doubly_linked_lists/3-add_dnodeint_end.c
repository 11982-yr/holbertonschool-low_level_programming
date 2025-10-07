#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 *
 * @head: the head of a list.
 * @n: the node.
 *
 * Return: the address of the new element, NULL if failed.
 */

dlistint_t *addnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *last;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	n->new = n;
	n->prev = NULL;


