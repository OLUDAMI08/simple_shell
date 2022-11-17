#include "main.h"

/*
 * getcmd - Gets commands to be executed
 * @line: full command
 * @delim: character that seperates commands
 * Return: pointer to command
 */

char **getcmd(char *line, const char *delim, ssize_t nread)
{
	char *token, **argv, *lineptr_copy;
	int i, num_tokens = 0;

	lineptr_copy = malloc(sizeof(char) * nread);
	if (lineptr_copy == NULL)
	{
		perror("Error");
		return (NULL);
	}
	strcpy(lineptr_copy, line);
	token = strtok(line, delim);

        while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
	argv[i] = malloc(sizeof(char) * strlen(token));
	strcpy(argv[i], token);

	token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr_copy);

	return (argv);
}
