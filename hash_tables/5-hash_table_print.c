#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 *
 * @ht: the hash table.
 *
 * Return: the key/value in array or list order.
 * If ht is NULL, don't print anything.
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		for (node = ht->array[i]; node != NULL; node = node->next)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
				first = 0;
			}
		}
	printf("}\n");
}
