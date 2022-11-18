#include "main.h"

/**
 * getpath - gets path of command
 * @cmd: argument passed
 * Return: complete path or NULL if failed
 */

char *getpath(char *cmd)
{
	char *path_token, *file_path, *path, *path_copy;
	int cmd_len, dir_len;
	struct stat buf;

	path = _getenv("PATH");
	cmd_len = _strlen(cmd);
	if (path)
	{
		path_copy = _strdup(path);
		path_token = strtok(path_copy, ":");
		dir_len = _strlen(path_token);
	while (path_token != NULL)
	{
		file_path = malloc(cmd_len + dir_len + 2);
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, cmd);
		_strcat(file_path, "\0");
		if (stat(file_path, &buf) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(cmd, &buf) == 0)
		return (cmd);
	return (NULL);
	}
	return (NULL);
}
