#include "dog.h"
#include <stdlib.h>

int _strlen(char *str);
char _strcopy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
 * _strlen - find the length of the string.
 *
 * @str: the string to be searched.
 *
 * Return: the length of the string.
 */

int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * _strcopy - create a copy of the string.
 *
 * @dest: the destination of the string.
 * @src: the source of the string to be copied.
 *
 * Return: a copy of the string.
 */

char _strcopy(char *dest, char *src)
{
	int index = 0;

	for (index = 0; src[index]; index++)
		dest[index] = src[index];

	dest[index] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog.
 *
 * @name: the name of the dog.
 * @age: the age of the dog.
 * @owner: the owner of the dog.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doggo;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	doggo = malloc(sizeof(dog_t));

	if (doggo == NULL)
		return (NULL);


