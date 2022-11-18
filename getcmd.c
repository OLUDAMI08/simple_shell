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

	lineptr_copy = malloc(sizeof(char) * nread + 1);
	if (lineptr_copy == NULL)
	{
		perror("Error");
		return (NULL);
	}
	_strcpy(lineptr_copy, line);
	token = strtok(line, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens + 1);

	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
	argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
	_strcpy(argv[i], token);

	token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr_copy);

	return (argv);
}
