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

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

/*_lsmanip.c*/
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

/*prints.c*/
int prompt(char *c);
int _putchar(char c);
size_t print_list(const list_t *h);
int printdir(char *str);

extern char **environ;

/*_envmanip.c*/
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
size_t _arrlen(char **arr);

/*_split.c*/
void free_av(char **av);
char **split_string(char *str, size_t delim);

/*_strmanip.c*/
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
size_t _strlen(char *s);

#endif /* SHELL_H */
