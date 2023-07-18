#include "main.h"
/**
 * tokenize - function that tokenizes a string
 * @command: string to be tokenized
 * @args: array to store tokenized arguments
 * Return: Number of arguments
 */

int tokenize(char *command, char *args[])
{
	int argc = 0;
	char *token;

	token = strtok(command, " \n");
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			/*This is to handle comments*/
			break;
		}
		args[argc++] = token;
		token = strtok(NULL, " \n");
	}
	args[argc] = NULL;
	return (argc);
}

#include "main.h"

/**
 * execute - fucntion that executes commands
 * @command: command to be executed
 * @args: the other arguments to be executed with command
 * Return: void
 */

void execute(char *command, char *args[])
{
	char *envp[] = {NULL};

	if (execve(command, args, envp) == -1)
	{
		perror(command);
		exit(EXIT_FAILURE);
	}
}

#include "main.h"

/**
 * sigint_handler - handle SIGINT signal to check stop flag
 * @signum: signal number
 * Return: void
 */

void sigint_handler(int signum __attribute__((unused)))
{
	stop = 1;
	signal(SIGINT, SIG_DFL);
	kill(getpid(), SIGINT);
}


#include "main.h"
/**
 * create_cprocess - calls the fork function
 * @command: input
 * Return: void
 */

void create_cprocess(char *command)
{
	int status;
	char *args[MAX_LINE_LENGTH], *full_path;
	pid_t pid;
	char cmd_path[MAX_LINE_LENGTH] __attribute__((unused));

	tokenize(command, args);
	if (builtin_cmds(args))
	{
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("failed to create child process");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
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
				free(full_path);
			}
			else
			{
				printf("./hsh: No such file or directory\n");
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
}
