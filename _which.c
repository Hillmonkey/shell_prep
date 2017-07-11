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
 * get_EV - get specified Environ Variable from envp
 * @var: variable name to search for in Environment Variables
 * @envp: full environment - array of strings
 * Return: pointer into Environ, or NULL if no match
 **/
char *get_EV(char *var, char **envp)
{
	int i = 0;

	while (envp[i])
	{
		if (str_eval(envp[i], var) >= _strlen(var))
		{
			printf("getEV-> %s\n", envp[i]);
			return (_strdup(envp[i]));
		}
		i++;
	}
	return (NULL);
}

/**
 * main - implements which - locate a command
 * @ac: number of command line arguments passed in
 * @av: all command line arguments as strings
 * @envp: all environment variables
 * Return: Always 0
 * Note: this does not implement the -a flag which would
 *       list all instances on the whole path
 */
int main(int ac, char **av, char **envp)
{
	unsigned int i, j;
	struct stat st;
	char *path, *full_path, *tmp, *path_slash;
	char *buf[BUFSIZE];

	UNUSED(ac);
	init_Cptr_buffer(buf, BUFSIZE);
	path = get_EV("PATH", envp);
	/* printf ("path: %p\n", path); */
	/* printf ("path: %s\n", path); */
	/* buf pointers point into tokenized path string */
	tmp = strtok(path, "=");
	/* printf("first tmp -> %s\n", tmp); */
	for (i = 0; tmp; i++)
	{
		buf[i] = tmp = strtok(NULL, ":");
		/* printf("i = %d--> tmp = %s\n", i, buf[i]); */
	}
	/* free(tmp); */
	i = 1;
	while (av[i])
	{
		j = 0;
		while (buf[j])
		{
			path_slash = str_concat(buf[j], "/");
			full_path = str_concat(path_slash, av[i]);
			free(path_slash);
			if (stat(full_path, &st) == 0)
			{
				printf("%s\n", full_path);
				/* break; */
			}
			free(full_path);
			j++;
		}
		/* free(full_path); */
		i++;
	}
	free(path);
	return (0);
}
