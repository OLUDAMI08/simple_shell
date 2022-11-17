#include "main.h"

/**
 * execmd - executes a command
 * @arg: argument
 */

void execmd(char **arg)
{
	pid_t pid;
	char *exit_s, *cmd = NULL, *actual_cmd = NULL;
	int status;

		cmd = arg[0];
		exit_s = "exit";
		if (!strcmp(cmd, exit_s))
			exit(0);
		actual_cmd = getpath(cmd);
		if (actual_cmd == NULL)
		{
			perror("./shell");
			return;
		}
		pid = fork();
		if (pid == -1)
		{
			perror(arg[0]);
			exit(1);
		}
	if (!pid)
	{
		execve(actual_cmd, arg, NULL);
		perror("./shell");
		for (i = 0 ; arg[i] ; i++;)
			free(arg[i]);
		free(arg);
		exit(1);
	}
	if (WEXITED(status))
	{
		WEXITSTATUS(status);
	}
	for (i = 0 ; arg[i] ; i++)
		free(arg[i]);
	free(arg);
}
