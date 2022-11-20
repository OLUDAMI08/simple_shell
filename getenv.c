#include "main.h"

/**
 * _getenv - gets value of an environment variable
 * @name: name of environment variable
 * Return: value of variable or NULL if not found
 */

char *_getenv(char *name)
{
	int i = 0;
	char *string = NULL;
	int position;

	position = _strlen(name) + 1;
	while (environ[i])
	{
		if (*environ[i] == *name)
		string = _strstr(environ[i], name);
		if (string != NULL)
			return (&string[position]);
		i++;
	}
	return (NULL);
}
