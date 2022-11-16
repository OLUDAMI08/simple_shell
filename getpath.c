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

	path = getenv("PATH");
	cmd_len = strlen(cmd);
	if (path)
	{
		path_copy = strdup(path);
		path_token = strtok(path_copy, ":");
		dir_len = strlen(path_token);
	while (path_token != NULL)
	{
		file_path = malloc(cmd_len + dir_len + 2);
		strcpy(file_path, path_token); 
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0"); 
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
