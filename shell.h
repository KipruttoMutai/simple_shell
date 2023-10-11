#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>

/*MACROS*/
#define BUFFER_SIZE 1024
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define MAX_TOKENS 1024

/*EXTERNAL VARIABLES*/
extern char **environ;

/*SHELL PROMPT FUNCTION*/
void prompt(void);

/*INPUT FUNCTIONS*/
char *get_input(void);
void br_puts(char *str);
char **tokenize_input(char *input);
int br_putchar(char c);
char **tokenize(char *str, const char *delim);

/**ENVIRONMENT FUNCTIONS*/
char *br_getenv(const char *name);
int br_setenv(char **args);
int br_unsetenv(char **args);

/*PATH FUNCTIONS*/
char *get_path(void);
char *find_in_path(char *command);

/*BUILTIN FUNCTIONS*/
int check_for_builtin(char **args);
void br_exit(char **args);
int br_env(void);
void br_cd(char **args);
int br_clear(char **args);

/*HELP*/
void br_help(void);

/*FREE FUNCTIONS*/
void free_tokens(char **ptr);
void free_last_input(void);

/*STRING FUNCTIONS*/
int br_strlen(const char *s);
char *br_strdup(const char *str);
int br_strcmp(const char *s1, const char *s2);
int br_atoi(const char *str);
int br_strncmp(const char *s1, const char *s2, size_t n);
char *br_strcpy(char *dest, char *src);

/*MAIN FUNCTION*/
int execute(char **argv);
int main(void);

/*SIGNAL FUNCTIONS*/
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);

#endif
