#include "holberton.h"

/**
 * get_path - return PATH
 * @envp: full environment - array of strings
 * Return: PATH variable or NULL if not found
 **/
char *get_path(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		/* printf("envp[%d] = %s", i, envp[i]); */
		if (str_eval(envp[i], "PATH=") >= 4)
		{
			return (envp[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_EV - get specified Environment Variable from envp
 * @var: environment variable name to search for
 * @envp: environment variables
 * Return: pointer to fresh copy of variable from environment,
 *         or NULL if no match found
 **/
char *get_EV(char *var, char **envp)
{
	int i = 0;

	while (envp[i])
	{
		if (str_eval(envp[i], var) >= _strlen(var))
			return (_strdup(envp[i]));
		i++;
	}
	return (NULL);
}

/**
 * main - prints each dir in path
 * @ac: number of command line args passed in
 * @av: array of strings of command line args
 * @envp: we use this to get at path variable
 * Return: Always 0.
 */
int main(int ac, char **av, char **envp)
{
	unsigned int i;
	char *path, *path2, *tmp;

	UNUSED(ac);
	UNUSED(av);

	path = get_path(envp);
	path2 = _strdup(path);

	/* determine # of pointers to malloc */
	tmp = strtok(path2, "=");
	printf("first tmp -> %s\n", tmp);
	for (i = 0; tmp; i++)
	{
		tmp = strtok(NULL, ":");
		printf("i = %d--> tmp = %s\n", i, tmp);
	}
	printf("final --> i = %d\n", i);
	return (0);
}
