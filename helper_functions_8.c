#include "shell.h"

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
        _eputs(info->fname);
        _eputs(": ");
        print_d(info->line_count, STDERR_FILENO);
        _eputs(": ");
        _eputs(info->argv[0]);
        _eputs(": ");
        _eputs(estr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
        int i;

        for (i = 0; buf[i] != '\0'; i++)
                if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
                {
                        buf[i] = '\0';
                        break;
                }
}
