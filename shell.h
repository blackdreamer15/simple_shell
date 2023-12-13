#ifndef SHELL_H
#define SHELL_H

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define BUFFER_SIZE 1024
#define MAX_ARGS 170

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>
#include <stddef.h>
#include <limits.h>


extern char **environ;

void display_prompt(void);
void get_input(char *input, size_t input_size);
void execute_prompt(const char *cmd);

void process_cmd(char *cmd);
void exec_cmd_with_args(const char *cmd);
void exec_cmd(const char *cmd);
int cmd_in_path_checker(const char *cmd);

void print_env(void);
void handle_setenv(const char *cmd);
void handle_unsetenv(const char *cmd);
int set_env_var(const char *var, const char *val);
int unset_env_var(const char *var);

void change_dir(const char *path);

int split_str(char *input, char *cmds[]);

void exit_shell(int status);
void handle_exit(char *command);

void _printf(const char *print_command, ...);
ssize_t _getline(char **lineptr, size_t *n);
char *_strtok(char *input_str, char *delimiter);
int _strncmp(const char *str1, const char *str2, size_t max_chars);

#endif /* SHELL_H */

