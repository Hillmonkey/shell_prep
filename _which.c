#include "holberton.h"

/**
 * get_path - return PATH
 * @envp - full environment - array of strings
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
 * get_EV - get specified environment variable from envp
 *
 *
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
 * _which - stat example
 * NOTE: TODO: This is a main function, should be shifted to a separate function
 * 		eventually ...
 * Return: Always 0.
 */
int main(int ac, char **av, char **envp)
{
    unsigned int i, len;
    struct stat st;
	char *path, *path2, *tmp;

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
    i = 1;
	/*
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
	*/
	return (0);
}
