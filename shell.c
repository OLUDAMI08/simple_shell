#include "main.h"

/**
 * main - run a simple shell
 * @ac: argument count
 * @argv: command line arguments
 * Return: Always zero
 */

int main(int ac, char **argv)
{
	char *lineptr = NULL, *PATH = NULL;
	size_t n = 0;
	ssize_t n_read;
	const char *delim = " \n";

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		prompt();
		n_read = getline(&lineptr, &n, stdin);
		if (n_read == -1)
		{
			return (-1);
		}
		argv = getcmd(lineptr, delim, n_read);
		if (argv == NULL)
		{
			free(lineptr);
			perror("Error");
			return (-1);
		}
		execmd(argv);
	}
	free(lineptr);
	return (0);
}
