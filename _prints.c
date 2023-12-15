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
		_putchar('#');
	else
		for (i = 0; i < strlen(c); i++)
			_putchar(c[i]);
	_putchar(' ');
	return (0);
}

/**
 * _puts- prints string
 *
 * @s: input string
 * Return: nothing
 */
void _puts(char *s)
{
	while (*s)
	{
		_puterr(*s);
		s++;
	}
}

/**
 * _perror- prints error
 * @str: input string
 *
 * Return: nothing
 */
void _perror(char *str)
{
	_puts("sh: ");
	print_int(_count);
	_puts(": ");
	_puts(str);
	_puts(": not found");
	_puterr('\n');
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
		printf("POP\n");
		current = current->next;
	}

	return (num_nodes);
}
