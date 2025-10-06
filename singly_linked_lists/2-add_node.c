#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 *
 * @head: the head of the list.
 * @str: the string
 *
 * Return: the address of the new element, NULL if it failed
 */

list_t *add_node(list_t **head, const char *str)
{
	char *dup;
	int len;
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	dup = strdup(str)
		if (dup == NULL)
		{
			free (new);
			return (dup);
		}

	for (len = 0; str[len])
