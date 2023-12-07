#ifndef SHELL_H
#define SHELL_H
#define MAX_INPUT 1024
#define MAX_ARGS 64
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysmacros.h>

int prompt(char *c);
int _putchar(char c);
extern char **environ;
void free_av(char **av);
char **split_string(char *str, size_t delim);
#endif /* SHELL_H */
