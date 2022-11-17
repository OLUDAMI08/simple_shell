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

	if (arg)
	{
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
		else
		pid = fork();
	if (!pid)
	{
		execve(actual_cmd, arg, NULL);
		perror("./shell");
		exit(1);
	}
	else if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			;
	}
	else
		perror("./shell");
	}
}
