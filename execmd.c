#include "main.h"

/**
 * execmd - executes a command
 * @cmd: command to be executed
 */

void execmd(char **arg)
{
	pid_t pid;
	char *cmd = NULL, actual_cmd = NULL;

	if (arg)
	{
		cmd = arg[0];
		actual_cmd = getpath(cmd);
	if (actual_cmd != NULL)
		pid = fork();
	if (!pid)
	{
		if (execve(actual_cmd, arg, NULL) = -1)
			perror("Error: ");
	}
	else
		wait(&status);
}
