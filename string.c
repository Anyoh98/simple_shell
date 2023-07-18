#include "main.h"

/**
 * _strcpy - function that copies a string
 * @destination: where copied string will be stored
 * @source: string that is to be copied
 * Return: copied string which is destination.
 */

char *_strcpy(char *destination, char *source)
{
	int i = 0, count = 0, j = 0;

	while (source[i] != '\0')
	{
		count++;
		i++;
	}

	for (j = 0; j < count; j++)
	{
		destination[j] = source[j];
	}
	destination[i] = '\0';
	return (destination);
}

#include "main.h"
/**
 * _strlen - function that counts the length of a string
 * @string: string whose length is to be counted
 * Return: the length of the string
 */

size_t _strlen(char *string)
{
	int i = 0;
	size_t length = 0;

	while (string[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

#include "main.h"
/**
 * _strcat - function that cocatenates 2 strings
 * @dest: string for appendment
 * @src: string to be appended
 * Return: appended string which is the detsination string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[j] != '\0')
		j++;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[j] = src[i];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

#include "main.h"

/**
 * _strchr - searches for 1rst occurence of a specific character
 * @str: string where character will be searched
 * @character: character to be searched
 * Return: pointer to first occurence of character
 */

char *_strchr(char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)(str));
		}
		str++;
	}
	/*Return NULL is character is not found*/
	return (NULL);
}

#include "main.h"

/**
 * _strcmp - Function that compares two strings
 * @s1: string to be compared.
 * @s2: String to be compared.
 * Return: s1[i] - s2[i].
 */

int _strcmp(char *s1, char *s2)
{
	int count1 = 0;
	int count2 = 0;
	int i;
	int j;

	for (i = 0; s1[i] != '\0'; i++)
	{
		count1++;
	}
	for (j = 0; s2[j] != '\0'; j++)
	{
		count2++;
	}
	if (s1[count1] == s2[count2])
	{
		int i = 0;

		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
			{
				return (s1[i] - s2[i]);
			}
			i++;
		}
	}
	return (0);
}
