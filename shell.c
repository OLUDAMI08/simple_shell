#include "main.h"

/**
 * main - run a simple shell
 * @ac: argument count
 * @argv: command line arguments
 * Return: Always zero
 */

int main(int ac, char **av)
{
	char  **argv, *lineptr = NULL;
	ssize_t n_read;
	const char *delim = " \t\a\r\n";
	int exitstatus = 0;
	info_t info[] = { INFO_INIT };
	static int hc = 0;
	(void)ac;

	signal(SIGINT, SIG_IGN);
	info->shell_name = av[0];
	while (1)
	{
		prompt();
		lineptr = _read(exitstatus);
		n_read = _strlen(lineptr) + 1;
		if (lineptr != NULL)
		{
			info->histcount = ++hc;
			info->cmd_name = lineptr;
			argv = getcmd(lineptr, delim, n_read);
			if (argv == NULL)
			{
				free(lineptr);
				continue;
			}
			if (handle_builtin(argv, lineptr, exitstatus) == 1)
			{
				free(lineptr);
				free_arg(argv);
				continue;
			}
			exitstatus = execmd(argv, lineptr, info);
		}
		else
			free(lineptr);
	}
	return (exitstatus);
}
