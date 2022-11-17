#include "main.h"
/**
* prompt - prints a prompt on the terminal
*/

void prompt(void)
{
	char *prompt = "($) ";
	ssize_t nwrite = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		nwrite = write(STDOUT_FILENO, prompt, 4);
		if (nwrite == -1)
			exit(0);
	}
}

/**
* _read - reads input
* Return: buffer input was read into or NULL on failure
*/

char *_read(void)
{
	ssize_t position, nread = 0;
	char *buf = NULL;
	size_t n = 0;
	int i;

	nread = getline(&buf, &n, stdin);

	if (nread == -1)
	{
		free(buf);
		if (isatty(STDIN_FILENO) != 0)
		{
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
		}
	}
	position = nread - 1;
	if (buf[position] == '\n' || buf[position] == '\t' || buf[position] == ' ')
		buf[position] = '\0';
	for (i = 0 ; buf[i] ; i++)
	{
		if (buf[i] == '#' && buf[i - 1] == ' ')
		{
			buf[i] = '\0';
			break;
		}
	}
	return (buf);
}

/**
* handle_builtin - checks for built-in command
* @arg: argument passed on command line
* @buf: buffer that stored argument
* Return: 0
*/

int handle_builtin(char **arg, char *buf)
{
	int i;
	char *exit_s = "exit";

	if (_strcmp(arg[0], exit_s) == 0)
	{
		for (i = 0; arg[i]; i++)
			free(arg[i]);
		free(arg);
		free(buf);
		exit(0);
	}
	return (0);
}
