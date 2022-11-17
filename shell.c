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
	ssize_t n_read;
	const char *delim = " \n";

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
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
		execmd(argv);
		}
	}
	free(lineptr);
	return (0);
}
