#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define UNUSED(x) (void)(x)
#define DELIM "\n \t"

/* #include "holberton.h" */

/**
 * main - super simple shell
 * Return: -1 on error status, 0 on normal execution
 */

int main(void)
{
	pid_t pid;
	int status;
	ssize_t linelen = 0;
	size_t linesize = 0;
	char *linebuf = NULL;
	char *my_argv[2];

	do {
		printf("($) ");
		linelen = getline(&linebuf, &linesize, stdin);
		my_argv[0] = strtok(linebuf, DELIM);
		my_argv[1] = NULL;
		/* printf("linebuf = %s", linebuf); */
		if (linelen > 0)
		{
			switch (pid = fork())
			{
				case -1:
					perror("fork()");
				case 0: /* child */
					status = execve(my_argv[0], my_argv, NULL);
					exit(status);
				default: /* parent */
					if (waitpid(pid, &status, 0) < 0)
					{
						perror("waitpid()");
						exit(EXIT_FAILURE);
					}
					/*
					if (WIFEXITED(status))
					{
						printf("WIFEXITED, status = %d\n", status);
						exit(WEXITSTATUS(status));
					}
					exit(EXIT_FAILURE);
					*/
			}
		}
		else
			printf("\n");
	} while (linelen > 0);
	/* TODO: wtf is up with linelen = 18446744073709551615 ??? */
	printf("linelen = %lu\n", linelen);
	free(linebuf);
	linebuf = NULL;
	if (linelen == -1)
		return (-1);
	else
		return (0);
}
