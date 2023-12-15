#include "shell.h"

/**
 * _puterr - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puterr(char c)
{
	return (write(2, &c, 1));
}
/**
 * print_int - prints integer
 * @n: integer to be printed
 * Return: number of characters printed
 */
int print_int(int n)
{
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_puterr('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_puterr(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_puterr(last + '0');

	return (i);
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
