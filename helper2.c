#include "holberton.h"

/**
 * _strdup - duplicate a string and place it in newly allocated space in
 *          memory
 * @str: string to be copied
 * Return: pointer to duplicated string, or NULL if sufficient memory
 *         is not available
 */
char *_strdup(char *str)
{
	char *new;
	unsigned int i, size;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	new = malloc(size * sizeof(char));
	for (i = 0; str[i] != '\0'; i++)
		new[i] = str[i];

	new[size] = '\0';
	return (new);
}
