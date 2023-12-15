#include "shell.h"

/**
 * _strdup- copies input string
 * @str : input string
 *
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	char *ptr;
	int i = 0;
	int n;

	if (str == 0)
		return (0);

	n = _strlen(str) + 1;

	ptr = malloc(sizeof(char) * (n));

	if (ptr == 0 || n == 0)
		return (0);

	while (*(str + i) != '\0')
	{
		*(ptr + i) = *(str + i);
		i++;
	}

	*(ptr + i) = *(str + i);
	return (ptr);
}

/**
 * _strlen- computes the length of string
 * @s: input string
 *
 * Return: length of string
 */
size_t _strlen(char *s)
{
	size_t i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;
	return (i);
}

/**
 * _strchr- finds a character in a given string
 * @s: input string
 * @c: character to find
 *
 * Return: the found character
 * otherwise return NULL
 */
char *_strchr(char *s, char c)
{
	if (!s)
		return (0);
	char *ptr = s;

	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (0);
}

/**
 * _strcat- concatenates 2 strings
 * @dest: destination string
 * @src: source string
 * Return: concatenated string(dest)
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; i >= 0; i++)
	{
		if (dest[i] == '\0')
			break;
	}
	for (j = 0; j >= 0; j++)
	{
		if (src[j] == '\0')
			break;
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp- compares two strings
 * @s1: input string 1
 * @s2: input string 2
 *
 * Return: positive int for s1>s2
 * 0 for s1 = s2
 * negative int for otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
