#include "main.h"

char **splitter(char *str, char *delim)
{
	char *token, **av;
	int i = 0;
	
	token = strtok(str, delim);

	while (i++)
	{
		if (token == NULL)
			return (NULL);
		av[i] = token;
		token = strtok(NULL, delim);
	}
	return (av);
}
