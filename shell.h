#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;
char **split_string(char *str, size_t delim);
#endif /* SHELL_H */
