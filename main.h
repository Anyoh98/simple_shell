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

volatile sig_atomic_t stop;
extern char **environ;

/*Function prototypes*/
void displayPrompt(void);
char *get_line(void);
void free_lineptr(char *cmd);
int tokenize(char *command, char *args[]);
void execute(char *command, char *args[]);
void create_cprocess(char *command);
void sigint_handler(int signum __attribute__((unused)));
int builtin_cmds(char *args[]);
void print_env(void);
char *find_path(char *command);

/*my helper functions*/
char *_strcpy(char *destination, char *source);
size_t _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_strchr(char *str, int character);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
#endif
