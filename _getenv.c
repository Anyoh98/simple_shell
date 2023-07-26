#include "main.h"

/**
 * _getenv - function that searches for the enviroment variable
 * @string: user input to be used for the search
 * Return: pointer to the string of the contents in the env variable
 */

char *_getenv(char *string)
{
	int string_len;
	char **env;

	string_len = _strlen(string);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(string, *env, string_len) == 0 && (*env)[string_len] == '=')
		{
			return (&((*env)[string_len + 1]));
		}
	}
	return (NULL);
}
