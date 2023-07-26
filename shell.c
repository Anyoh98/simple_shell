#include "main.h"

/**
 * main - main function
 * @ac: number of command line arguments
 * @av: command line arguments
 * Return: 0 on completion
 */


int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	sig_atomic_t stop = 0;
	char *command;

	struct sigaction sa;

	sa.sa_handler = sigint_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (!stop)
	{
		displayPrompt();
		command = get_line();
		if (command == NULL)
		{
			printf("\n");
			break;
		}
		create_cprocess(command, av[0]);
		free(command);
	}
	/*free(command);*/
	return (0);
}
