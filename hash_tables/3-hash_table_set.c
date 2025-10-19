#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
* make_node - create a hash node with duplicated key/value.
* @key: key string.
* @value: value string.
*
* Return: pointer to new node on success, NULL on failure.
*/
static hash_node_t *make_node(const char *key, const char *value)
{
	hash_node_t *node;
	char *k, *v;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	k = strdup(key);
	if (k == NULL)
	{
		free(node);
		return (NULL);
	}

	v = strdup(value);
	if (v == NULL)
	{
		free(k);
		free(node);
		return (NULL);
	}

	node->key = k;
	node->value = v;
	node->next = NULL;
	return (node);
}

/**
* hash_table_set - add or update an element in the hash table.
* @ht: the hash table.
* @key: the key.
* @value: the value associated with the key.
*
* Return: 1 on success, 0 on failure.
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	size_t index;
	hash_node_t *node, *new_node;
	char *new_value;

	if (!ht || !ht->array || ht->size == 0 || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(node->value);
			node->value = new_value;
			return (1);
		}
	}

	new_node = make_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
