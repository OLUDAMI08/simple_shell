#include "main.h"

/**
 * execmd - executes a command
 * @cmd: command to be executed
 */

void execmd(char **arg)
{
	pid_t pid;
	char *exit_s, *cmd = NULL, *actual_cmd = NULL;
	int status;

	if (arg)
	{
		cmd = arg[0];
		exit_s = "exit";
		if (!strcmp(cmd, exit_s))
			exit(0);
		actual_cmd = getpath(cmd);
		if (actual_cmd == NULL)
		{
			perror("Error");
			return;
		}
		else
		pid = fork();
	if (!pid)
	{
		execve(actual_cmd, arg, NULL);
		perror("Error");
		exit(1);
	}
	else if (pid > 0)
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
		for (i = 0; arg[i]; i++)
			free(arg[i]);
		free(arg);
		perror("Error");
	
	}
}
