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

#include "main.h"

/**
 * _strspn - gets the length of a substring
 * @str: main string inputed
 * @charset: string to compare to main string
 * Return: number of bytes in str that cosnsits of chars from charset
 */

unsigned int _strspn(char *str, char *charset)
{
	size_t count = 0;
	char *ptr;

	while (*str)
	{
		ptr = charset;
		while (*ptr)
		{
			if (*str == *ptr)
			{
				count++;
				break;
			}
			ptr++;
		}
		if (*ptr == '\0')
		{
			break;
		}
		str++;
	}
	return (count);
}

#include "main.h"

/**
 * _strncpy - function that copies n bytes of a string to another
 * @dest: destination string
 * @src: string to be copied to dest
 * @n: number of bytes to be copied
 * Return: pointer to dest
 */

char *_strncpy(char *dest, char *src, size_t n)
{
	size_t index = 0;

	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	if (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

#include "main.h"

/**
 * _strncmp - function taht comapres up to n bytes of 2 strings
 * @str1: string we want to compare
 * @str2: string we will be comparing to
 * @n: number of bytes to be compared
 * Return: 0 on sucess and diff of both strings on failure
 */

int _strncmp(char *str1, char *str2, size_t n)
{
	size_t i = 0;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		if (str1[i] == '\0')
		{
			break;
		}
	}
	return (0);
}
