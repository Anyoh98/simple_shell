#include "main.h"

/**
 * find_path - function that searches for the commands full path
 * @command: command to be searched for the path
 * Return: pointer to the found path string
 */

char *find_path(char *command)
{
	char *env_path, *path;
	char cmd_path[MAX_LINE_LENGTH];

	env_path = _getenv("PATH");
	path = strtok(env_path, ":");
	while (path != NULL)
	{
		_strcpy(cmd_path, path);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, command);

		if (access(cmd_path, X_OK) == 0)
		{
			return (_strdup(cmd_path));
		}
		path = strtok(NULL, ":");
	}
	return (NULL);
}
