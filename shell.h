#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysmacros.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

extern char **environ;

int _putchar(char c);
int prompt(char *c);
char **split_string(char *str);
void free_av(char **av);
int execute_cmd(char **av, pid_t pid, int *status, int flag);

#endif /* SHELL_H */
