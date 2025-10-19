#include "hash_tables.h"

/**
 * key_index - gives the index of a key.
 *
 * @key: the key.
 * @size: the size of the array.
 *
 * Return: the index which the key should be stored.
 *
 * Description: uses the djb2 algorithm.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
