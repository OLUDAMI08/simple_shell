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
	char *PATH = NULL;
	(void)ac;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	printf("path: %s\n", PATH);
	if (PATH == NULL)
	{
		return (-1);
	}
	while (1)
	{
		prompt();
		lineptr = _read();
		n_read = _strlen(lineptr) + 1;
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
