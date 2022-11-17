#include "main.h"

/**
 * main - run a simple shell
 * @ac: argument count
 * @argv: command line arguments
 * Return: Always zero
 */

int main(int ac, char **argv)
{
	char *prompt = "(shell) $ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t n_read;
	const char *delim = " \n";

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (ac == 1)
			printf("%s", prompt);
		}
		n_read = getline(&lineptr, &n, stdin);
		if (n_read == -1)
		{
			return (-1);
		}
		argv = getcmd(lineptr, delim, n_read);
		if (argv == NULL)
		{
			return (-1);
		}
		execmd(argv);
	}
	free(lineptr);
	return (0);
}
