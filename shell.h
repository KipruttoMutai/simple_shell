#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*SHELL PROMPT FUNCTION*/
void prompt(void);

/*INPUT FUNCTIONS*/
char *get_input(void);
void br_puts(char *str);

/*STRING FUNCTIONS*/
int br_strlen(const char *s);

#endif
