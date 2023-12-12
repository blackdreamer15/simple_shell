#include "shell.h"

/**
 * _printf - custom implementation of printf
 * @format: format string
 * @...: variable arguments
 */
void _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

/**
 * _strncmp - Compare n characters of two strings
 * @str1: The first string
 * @str2: The second string
 * @n: The max number of characters to compare
 *
 * Return:
 *   0 if str1 == str2,
 *   a negative value if str1 < str2,
 *   a positive value if str1 > str2.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && (*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
	
		str1++;
		str2++;
		n--;
	}

	return (0);
}

/**
 * _strtok - breaks up a string into tokens
 * @input_str: string to be tokenized.
 * @delim: character specifying where the string is to be broken.
 * Return: pointer to a tokenized string
 */
char *_strtok(char *input_str, char *delim)
{
	static char *val;
	char *result = input_str;

	if (!input_str)
		input_str = val;

	if (!input_str)
		return (NULL);

	while (*input_str && (*input_str == *delim || !*delim))
		input_str++;

	if (!*input_str)
		return (NULL);

	result = input_str;

	while (*input_str && (*input_str != *delim || !*delim))
		input_str++;

	if (*input_str)
	{
		*input_str = '\0';
		val = input_str + 1;
	}
	else
		val = input_str;

	return (result);
}
