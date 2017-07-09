#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 * @argc: number of arguments
 * @argv: array of strings - the commmand line arguments
 * @envp: array of strings - environment passed in
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	pid_t child_pid, my_pid;
	int status, i;
	static const char * const myargv[] = {"/bin/ls", "-al", "/tmp/", NULL};

	(void)argv;
	(void)argc;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		my_pid = getpid();
		if (child_pid == 0)
		{
			printf("###--> child process #%u\n", my_pid);
			execve(myargv[0], myargv, envp);
			sleep(1);
		}
		else
		{
			wait(&status);
			printf("Parent #%d PID #%u\n", i,  my_pid);
		}
	}
	return (0);
}
