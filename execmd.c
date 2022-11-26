#include "main.h"

/**
 * execmd - executes a command
 * @arg: argument passed
 */

int execmd(char **arg, char *buf)
{
	pid_t pid;
	char *cmd = NULL, *actual_cmd = NULL;
	char *PATH;
	int status, result, exitstatus = 0;
	struct stat buffer;
	int cmdflag = 0;

	if (*buf != '\0')
	{
		cmd = arg[0];
		if (stat(cmd, &buffer) == 0)
		{
			cmdflag++;
			actual_cmd = cmd;
		}
		else
		{
			PATH = _getenv("PATH");
			if (PATH == NULL)
			{
				free_arg(arg);
				free(buf);
				perror("Error");
				return (127);
			}
			actual_cmd = getpath(cmd);
		}
		if (actual_cmd == NULL)
		{
			free(actual_cmd);
			free_arg(arg);
			free(buf);
			perror("Error");
			return (127);
		}

		pid = fork();
		if (pid == -1)
		{
			perror(arg[0]), exit(1);
		}
	if (pid == 0)
	{
		result = execve(actual_cmd, arg, NULL);
		if (result == -1)
		{
			perror(arg[0]);
			free_arg(arg);
			free(actual_cmd);
			free(buf);
			exit(126);
		}
	}
	}
	wait(&status);
	if (WIFEXITED(status))
		exitstatus = WEXITSTATUS(status);
	free_arg(arg);
	free(buf);
	if (!cmdflag)
	free(actual_cmd);
	return (exitstatus);
}
