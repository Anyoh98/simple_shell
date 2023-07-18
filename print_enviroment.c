#include "main.h"

/**
 * print_env - Function that prints the enviroment variable
 * Return: void
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
