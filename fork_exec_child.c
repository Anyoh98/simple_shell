#include "main.h"

/**
 * child_process - creates a child process
 * Return: pid to parent or 0 to child
 */

pid_t child_process(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("failed to create child process");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

#include "main.h"

/**
 * execute_child - execute the child process
 * @cmd_path: path of command to be executed
 * @args: command line arguments
 * Return: void
 */

void execute_child(char *cmd_path, char **args)
{
	char *full_path;

	if (_strchr(args[0], '/') != NULL)
	{
		execute(args[0], args);
	}
	else
	{
		full_path = find_path(args[0]);
		if (full_path != NULL)
		{
			execute(full_path, args);
		}
		else if (!isatty(STDIN_FILENO))
		{
			fprintf(stderr, "%s: 1: %s: not found\n", cmd_path, args[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_FAILURE);
}
