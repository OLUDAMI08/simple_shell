#include "main.h"

/**
 * getcmd - gets commands to be executed
 * @line: full command
 * @delim: character that seperates commands
 * @nread: number of bytes read
 * Return: pointer to command
 */

char **getcmd(char *line, const char *delim, ssize_t nread)
{
	char *token, **argv, *lineptr_copy;
	int i, num_tokens = 0;
	(void)nread;

	lineptr_copy = _strdup(line);
	token = strtok(line, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens + 1);
	if (argv == NULL)
	{
		free(line);
		free(lineptr_copy);
		exit(1);
	}

	token = strtok(lineptr_copy, delim);
	if (token == NULL)
	{
		free(lineptr_copy);
		free(argv);
		return (NULL);
	}
	for (i = 0 ; token != NULL ; i++)
	{
	argv[i] = _strdup(token);
	token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr_copy);

	return (argv);
}
