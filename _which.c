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
		if (_strcmp(envp[i], "PATH=") >= 4)
			return (envp[i]);
	}
	return (NULL);
}

/**
 * walk_path - return directories from PATH, sequentially
 *
 * Return: string containing a directory from the path
 * NOTE: This uses strtok.  only walk a copy of your envp!
 **/

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
	path2 = _strdup(path); /* make sure this works */
	path = _strdup(path2); /* this is copy to trash while finding # of tokens */
	/* determine # of pointers to malloc */
	tmp = strtok(path2, "=");
	printf("first tmp -> %s", tmp);
	for (i = 0; tmp; i++)
	{
		tmp = strtok(NULL, ":");
		printf("%d--> %s\n", i, tmp);
	}
	printf("final --> i = %d", i);
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
