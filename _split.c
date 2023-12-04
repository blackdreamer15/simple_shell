#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * split_string- splits strings by " "
 * @str: input string
 * @delim: demilter
 * Return: pointer to array of commands(strings)
 */

char **split_string(char *str, char *delim)
{
	size_t len = strlen(str);
	char **words = malloc(len + 1);
	int count = 0;
	char *token = strtok(str, delim);

	str[strcspn(str, "\n")] = '\0';

	while (token != NULL)
	{
		words[count] = malloc(strlen(token) + 1);
		strcpy(words[count], token);
		count++;

		token = strtok(NULL, delim);
	}
	words[count] = NULL;
	return (words);
}
