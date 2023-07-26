#include "main.h"

/**
 * cmd_setenv - function that modifies the value of an enviroment var
 * @args: array of strings
 * Return: Always 0 on sucess and 1 otherwise.
 */

void cmd_setenv(char **args)
{
	char *message;

	message = "Usage: setenv VARIABLE VALUE\n";
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, message, _strlen(message));
		/*return (1);*/
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		/*return (1);*/
	}
	/*return (0);*/
}

#include "main.h"

/**
 * cmd_unsetenv - function that removes an enviroment varaible
 * @args: array of strings
 * Return: always 0 on sucess and 1 otherwise
 */

void cmd_unsetenv(char **args)
{
	/*char *message;*/

	/*message = "Usage: unsetenv VARIABLE\n";*/
	if (args[1] == NULL)
	{
		perror("unsetenv: Invalid syntax");
		/*write(STDERR_FILENO, message, _strlen(message));*/
		/*return (1);*/
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		/*return (1);*/
	}
	/*return (0);*/
}

#include "main.h"

/**
 * cmd_exit - exits the function with and without status
 * @args: command line arguments
 * Return: void
 */

void cmd_exit(char **args)
{
	int status_exit;

	status_exit = args[1] != NULL ? _atoi(args[1]) : 0;
	exit(status_exit);
}

#include "main.h"

/**
 * cmd_printenv - prints out all env variables
 * @args: command line arguments
 * Return: void
 */

void cmd_printenv(char **args __attribute__((unused)))
{
	print_env();
}

#include "main.h"

/**
 * builtin_cmds - handles execution of built in commands
 * @args: arg array where built in command will be checked
 * Return: 1 if its built in and 0 on failure
 */

int builtin_cmds(char *args[])
{
	size_t i;

	Command commands[] = {
		{"exit", cmd_exit },
		{"env", cmd_printenv},
		{"setenv", cmd_setenv},
		{"unsetenv", cmd_unsetenv},
	};
	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
	{
		if (_strcmp(args[0], commands[i].name) == 0)
		{
			commands[i].action(args);
			return (1);
		}
	}
	return (0);
}
