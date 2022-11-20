#include "main.h"

/**
 * execmd - executes a command
 * @arg: argument passed
 */

int execmd(char **arg, char *buf)
{
	pid_t pid;
	char *cmd = NULL, *actual_cmd = NULL;
	int status;

	if (arg)
	{
		cmd = arg[0];
		handle_builtin(arg, buf);
		actual_cmd = getpath(cmd);
		if (actual_cmd == NULL)
		{
			free(actual_cmd);
			perror("Error");
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror(arg[0]), exit(1);
		}
	if (pid == 0)
	{
		execve(actual_cmd, arg, NULL), exit(1);
	}
	else if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	}
	else
	{
		free_arg(arg);
		free(buf);
		perror("Error");
	}
	return (0);
}
