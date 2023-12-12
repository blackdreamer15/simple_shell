#include "shell.h"

/**
 * split_commands - Splits input commands based on the ";" delimiter
 * @input: The input string containing commands separated by ";"
 * @commands: An array to store the individual commands
 * Return: The number of commands
 */

int split_commands(char *input, char *commands[])
{
	int cmd_count = 0;
	char *token = strtok(input, ";");

	while (token != NULL && cmd_count < 10)
	{
		commands[cmd_count++] = token;
		token = strtok(NULL, ";");
	}
	return (cmd_count);
}
