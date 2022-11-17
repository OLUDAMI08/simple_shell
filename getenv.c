#include "main.h"

/**
 * _getenv - gets value of an environment variable
 * @name: name of environment variable
 * Return: value of variable or NULL if not found
 */

char *_getenv(const char *name)
{
	int i = 0;
	extern char **environ;
	char *string;
	int position;

	while (environ[i])
	{
		string = strstr(environ[i], name);
		if (string != NULL)
			return (&string[position]);
		i++;
	}
	return (NULL);
}
