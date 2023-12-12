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


/**
 * print_list - prints the contents of a linked list
 * @h: the given linked list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	int num_nodes = 0;
	const list_t *current = h;

	while (current)
	{
		if (current->str)
			printf("[%d] %s\n", current->len, current->str);
		else
			printf("[0] (nil)\n");

		num_nodes++;
		current = current->next;
	}

	return (num_nodes);
}

/**
 * printdir-prints directory in path
 * @str: input string
 *
 * Return: 0 on success
 */
int printdir(char *str)
{
	char *tmp = getenv(str);

	while (*tmp)
	{
		if (*tmp == ':')
		{
			_putchar('\n');
			tmp++;
			continue;
		}
		_putchar(*tmp);
		tmp++;
	}
	return (0);
}
