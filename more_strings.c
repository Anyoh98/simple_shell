#include "main.h"

/**
 * _strdup - Function that duplicates a string
 * @str: string to be duplicated
 * Return: pointer to new string that has been duplicated
 */

char *_strdup(char *str)
{
	size_t len;
	char *new_str;

	len = _strlen(str) + 1; /*+1 is to include the null terminator*/
	new_str = (char *)malloc(len);
	if (new_str != NULL)
	{
		_strcpy(new_str, str);
	}
	return (new_str);
}
