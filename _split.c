#include "shell.h"

/**
 * split_string- splits strings by " "
 * @str: input string
 * @len: length of str
 * Return: pointer to array of commands(strings)
 */

char **split_string(char *str, size_t len)
{
	char *delim = " ";
	char **words = malloc(len + 1);
	int count = 0;
	char *token;

	str[strcspn(str, "\n")] = '\0';
	token = strtok(str, delim);

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

/**
 * free_av- frees av
 * @av: input array
 * Return: Nothing
 */
void free_av(char **av)
{
	int i;

	for (i = 0; av[i] != NULL; i++)
	{
		free(av[i]);
	}
	free(av);
}
