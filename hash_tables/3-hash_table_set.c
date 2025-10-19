#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/** 
 * hash_table_set - adds an element to the hash table.
 *
 * @ht: the hash table. 
 * @key: the key. 
 * @value: the value stored with the key.
 *
 * Return: 1 on success, 0 otherwise.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	size_t index;
	hash_node_t *node;
	char *new_value, *new_key;
	hash_node_t *new_node;

	if (!ht || !ht->array || ht->size == 0 || !key || *key == '\0' || !value)
	return 0;

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node; node = node->next)
	{
	if (strcmp(node->key, key) == 0)
	{
	new_value = strdup(value);
	if (!new_value)
	return 0;
	free(node->value);
	node->value = new_value;
	return 1;
	}
	}

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	return 0;

	new_key = strdup(key);
	if (!new_key)
	{
	free(new_node);
	return 0;
	}

	new_value = strdup(value);
	if (!new_value)
	{
	free(new_key);
	free(new_node);
	return 0;
	}

	new_node->key = new_key;
	new_node->value = new_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return 1;
}
