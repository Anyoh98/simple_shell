#include "main.h"

/**
 * cd_to_userhomedir - changes currrent wd to users home dir
 * Return: 1 on success and 0 other wise
 */

int cd_to_userhomedir(void)
{
	char *home_directory;

	home_directory = _getenv("HOME");
	if (home_directory)
	{
		if (chdir(home_directory) != 0)
		{
			perror("cd");
			return (0);
		}
		else
			setenv("PWD", home_directory, 1);
	}
	else
	{
		perror("cd: No home directory found");
		return (0);
	}
	return (1);
}

#include "main.h"

/**
 * cd_to_prev - change current wd to previous wd
 * @former_pwd: old wokring directory
 * Return: 1 on sucess and 0 otherwise
 */

int cd_to_prev(char *former_pwd)
{
	if (former_pwd != NULL)
	{
		if (chdir(former_pwd) != 0)
		{
			perror("cd");
			return (0);
		}
		write(STDOUT_FILENO, former_pwd, _strlen(former_pwd));
		write(STDOUT_FILENO, "\n", 1);
		setenv("PWD", former_pwd, 1);
	}
	else
	{
		perror("cd: No home directory found");
		return (0);
	}

	return (1);
}

#include "main.h"

/**
 * cd_to_directory - change current wd to specified directory
 * @dir: the directory we want to open
 * Return: 1 on sucess and 0 otherwise
 */

int cd_to_directory(char *dir)
{
	char cwd[5000];

	if (chdir(dir) != 0)
	{
		perror("cd");
		return (0);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		setenv("PWD", cwd, 1);
	else
		perror("cd");
	return (1);
}


#include "main.h"

/**
 * my_cd - function to change directory
 * @args: command line arguments.
 * Return: 1 on sucess.
 */

int my_cd(char *args[])
{
	char *former_pwd;

	former_pwd = _getenv("OLDPWD");
	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		return (cd_to_userhomedir());
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		return (cd_to_prev(former_pwd));
	}
	else
	{
		return (cd_to_directory(args[1]));
	}
	return (1);
}
