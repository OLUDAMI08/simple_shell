#include "main.h"

/**
 * execmd - executes a command
 * @arg: argument passed
 */

int execmd(char **arg, char *buf)
{
	pid_t pid;
	char *cmd = NULL, *actual_cmd = NULL;
	int status, result;

	if (*buf != '\0')
	{
		cmd = arg[0];
		handle_builtin(arg, buf);
		actual_cmd = getpath(cmd);
		pid = fork();
		if (pid == -1)
		{
			perror(arg[0]), exit(1);
		}
	if (pid == 0)
	{
		if (actual_cmd == NULL)
		{
			free(actual_cmd);
			perror("Error");
			exit(127);
		}
		result = execve(actual_cmd, arg, NULL);
		if (result == -1)
		{
			perror(arg[0]);
			free_arg(arg);
			free(buf);
			exit(126);
		}
	}
	}
	wait(&status);
	if (WIFEXITED(status))
		WEXITSTATUS(status);
	free_arg(arg);
	free(buf);
	return (0);
}
