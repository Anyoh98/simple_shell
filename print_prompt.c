#include "main.h"

/**
 * displayPrompt - Function that displays a prompt
 * Return: void
 */

void displayPrompt(void)
{
	char *prompt;

	if (isatty(STDIN_FILENO))
	{
		prompt = "Myshell$ ";
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		/*printf("Myshell$ "); prints the prompt*/
		fflush(stdout); /*empty output buffer in file stream*/
	}
}

#include "main.h"

/**
 * get_line - Function that reads the inputfrom the user
 * Return: string that contains the line that was read
 */

char *get_line(void)
{
	ssize_t bytesread;
	size_t line_length;
	char buffer[MAX_LINE_LENGTH];
	char *line = NULL;

	bytesread = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	if (bytesread == -1)
	{
		perror("failed to read line");
		exit(EXIT_FAILURE);
	}
	if (bytesread == 0) /*eof has been reached*/
	{
		/*printf("\n");*/
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	buffer[bytesread] = '\0';/*add NULL character at end of buffer*/
	line_length = _strlen(buffer);
	line = (char *)malloc(line_length + 1);
	if (line == NULL)
	{
		perror("memory alocation failed");
		exit(EXIT_FAILURE);
	}
	_strcpy(line, buffer);
	return (line);
}

#include "main.h"

/**
 * free_lineptr - function that frees the line ptr
 * @cmd: string to be freed
 */

void free_lineptr(char *cmd)
{
	free(cmd);
}
