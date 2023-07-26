#include "main.h"

/**
 * free_and_get_result - cleanup memory and return final result
 * @str_len: length of the string/line.
 * @string: the line to be read
 * Return: pointer to the string or NULL otherwisze
 */

char *free_and_get_result(char *string, int str_len)
{
	string = realloc(string, (str_len + 1) * sizeof(char));
	if (string == NULL)
	{
		perror("realloc");
		return (NULL);
	}
	string[str_len] = '\0';
	return (string);
}

#include "main.h"

/**
 * line_resize - Adjusts the size of the buffer
 * @string: pointer to buffer pointer
 * @str_len: lenght of the string
 * @new_size: new string size
 * Return: void
 */

void line_resize(char **string, int *str_len, int new_size)
{
	char *temp;

	temp = realloc(*string, new_size * sizeof(char));
	if (temp == NULL)
	{
		perror("realloc");
		free(*string);
		*string = NULL;
	}
	else
	{
		*string = temp;
		*str_len = new_size;
	}
}

#include "main.h"

/**
 * catenate_char - appends each character one by one
 * @string: ^pointer to th ebuffer pointer
 * @str_len: length of the string
 * @character: character to be appended
 * Return: void
 */

void catenate_char(char **string, int *str_len, char character)
{
	if (*str_len % MAX_LINE_LENGTH == 0)
	{
		line_resize(string, str_len, *str_len + MAX_LINE_LENGTH);
	}
	(*string)[*str_len] = character;
	(*str_len)++;
}

#include "main.h"

/**
 * _getline - my getline function with static variables to read line
 * Return: pointer to the line read
 */

char *_getline()
{
	int str_len = 0;
	char *string = NULL;
	char character;

	fflush(stdout);
	while (1)
	{
		if (read(STDIN_FILENO, &character, 1) < 1)
		{
			if (str_len > 0)
			{
				return (free_and_get_result(string, str_len));
			}
			return (NULL);
		}
		if (character == '\n')
		{
			return (free_and_get_result(string, str_len));
		}
		catenate_char(&string, &str_len, character);
	}
}
