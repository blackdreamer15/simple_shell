#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * prompt- prints prompt
 *
 * @c: input string
 * Return: 1 on success
 */
int prompt(char *c)
{
	size_t i;

	if (c == 0)
		_putchar('$');
	else
		for (i = 0; i < strlen(c); i++)
			_putchar(c[i]);
	_putchar(' ');
	return (0);
}
