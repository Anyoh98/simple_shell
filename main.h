#ifndef MAIN_H
#define MAIN_H

#define MAX_LINE_LENGTH 1024


/*standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <errno.h>

/**
 * struct Command - Command with is corresponding action function
 *
 * @name: name of the command
 * @action: function that takes the name as argument
 * Description: cmd struct reps a cmd in a prg with its associated action.
 */
typedef struct Command
{
	char *name;
	void (*action)(char **);
} Command;

extern char **environ;

/*Function prototypes*/
void displayPrompt(void);
char *get_line(void);
void free_lineptr(char *cmd);
int tokenize(char *command, char *args[]);
void execute(char *command, char *args[]);
void create_cprocess(char *command, char *shell_name);
void sigint_handler(int signum __attribute__((unused)));
int builtin_cmds(char *args[]);
void print_env(void);
char *find_path(char *command);

char *_strtok(char *str, const char *delimiters);

/*Function for child process*/
void execute_child(char *cmd_path, char **args);
pid_t child_process(void);

/*Function for static _getline function*/
void catenate_char(char **string, int *str_len, char character);
void line_resize(char **string, int *str_len, int new_size);
char *free_and_get_result(char *string, int str_len);
char *_getline(void);

/*functions for the enviroment variables*/
int _setenv(char *args[]);
int _unsetenv(char *args[]);
char *_getenv(char *string);

/*my helper functions*/
char *_strcpy(char *destination, char *source);
size_t _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_strchr(char *str, int character);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *str1, char *str2, size_t n);

/*atoi function*/
int _atoi(char *s);

/*Builtin functions*/
/*cd*/
int my_cd(char *args[]);
int cd_to_directory(char *dir);
int cd_to_userhomedir(void);
int cd_to_prev(char *former_pwd);

/*for exit, and envs*/
void cmd_printenv(char **args);
void cmd_unsetenv(char **args);
void cmd_exit(char **args);
void cmd_setenv(char **args);

unsigned int _strspn(char *str, char *charset);
#endif
