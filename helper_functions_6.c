#include "shell.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 * Return: void
 */
void _eputs(char *str)
{
        int i = 0;

        if (!str)
                return;
        while (str[i] != '\0')
        {
                _eputchar(str[i]);
                i++;
        }
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1. On error, -1 is returned,
 * and errno is set appropriately.
 */
int _eputchar(char c)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(2, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 * Return: On success 1. On error, -1 is returned,
 * and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(fd, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 * Return: the number of chars printed
 */
int _putsfd(char *str, int fd)
{
        int i = 0;

        if (!str)
                return (0);
        while (*str)
        {
                i += _putfd(*str++, fd);
        }
        return (i);
}