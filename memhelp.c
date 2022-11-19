#include "main.h"

/**
*
*/
/*
char *makemem(size_t memsize)
{
	char *mem;

	mem = malloc(sizeof char * memsize);
	if (mem == NULL)
		exit(1);
	return (mem);
}
*/
/**
*
*/
void free_arg(char **arg)
{
	int i;

	for (i = 0; arg[i]; i++)
		free(arg[i]);
	free(arg);
}
