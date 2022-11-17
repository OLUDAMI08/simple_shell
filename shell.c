#include "main.h"

/**
 * main - run a simple shell
 * @ac: argument count
 * @argv: command line arguments
 * Return: Always zero
 */

int main(int ac, char **argv)
{
	char *lineptr = NULL;
	ssize_t n_read;
	const char *delim = " \n";
	(void)ac;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		prompt();
		lineptr = _read();
		n_read = strlen(lineptr) + 1;
		if (*lineptr != '\0')
		{
		argv = getcmd(lineptr, delim, n_read);
		if (argv == NULL)
		{
			free(lineptr);
			continue;
		}
		execmd(argv, lineptr);
		}
	}
	free(lineptr);
	return (0);
}
