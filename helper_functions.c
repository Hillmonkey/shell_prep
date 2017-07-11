#include "holberton.h"

/**
 *_strcmp - function that compares two strings.
 *@s1:argument
 *@s2:arguments
 *
 *Return: 0 if strings are identical, or diff in ascii values at first variance
*/

int _strcmp(char *s1, char *s2)
{
	int a = 0;
	int b = 0;

	while (s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a])
	{
		a++;
	}
	if (s1[a] != s2[a])
	{
		b = s1[a] - s2[a];
		return (b);
	}
	return (0);

}
/**
 *str_eval - function that compares two strings.
 *@s1:argument
 *@s2:arguments
 *Return: *** position where first diff is found in the 2 strings
*/

int str_eval(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a])
		a++;
	return (a);
}
/**
 **_strcpy - function returns copy of a string.
 *@src: string
 *@dest: target string (with enough space to accept copy)
 *Return: pointer to dest, which now contains copy of src
**/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while ((dest[i] = src[i]))
		i++;

	return (dest);
}
/**
**_strlen - length of the string
**@s: pointer to string
**Return: Lenght of string
**/
int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; i++)
	{
		++s;
	}
	return (i);
}

