#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	ssize_t linelen = 0;
	size_t linesize = 0;
	char *linebuf = NULL;

	do {
		printf("($) ");
		linelen = getline(&linebuf, &linesize, stdin);
		if (linelen > 0)
			printf("%s", linebuf);
		else
			printf("\n");
	} while (linelen > 0);

	free (linebuf);
	linebuf = NULL;
	if (linelen == -1)
		return (-1);
	else
		return (0);
}
