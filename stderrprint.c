#include "main.h"

/**
 * errputs - writes a string to standard error
 * @s: string to print
 * Return: number of bytes written or -1 on failure
 */

int errputs(char *s)
{
	int nwrite, len = _strlen(s);

	nwrite = write(2, s, len);

	return (nwrite);
}

/**
 * print_err - prints error message to standard error
 * @info: struct containing info to be printed
 * Return: Always 0
 */

int print_err(info_t *info)
{
	char *s, histcount[2] = {0, 0};

	s = info->shell_name;
	strcat(s, ": ");
	histcount[0] = info->histcount + 48;
	histcount[1] = '\0';
	strcat(s, histcount);
	strcat(s, ": ");
	strcat(s, info->cmd_name);
	strcat(s, ": not found\n");

	errputs(s);

	return (0);
}
