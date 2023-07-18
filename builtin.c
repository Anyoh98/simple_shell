#include "main.h"

/**
 * builtin_cmds - handles execution of built in commands
 * @args: arg array where built in command will be checked
 * Return: 1 if its built in and 0 on failure
 */

int builtin_cmds(char *args[])
{
	if (args[0] == NULL)
	{
		return (1);
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		stop = 1;
		return (1);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}
