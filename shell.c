#include "shell.h"

/**
 * main- the shell
 * @ac: number of argument passed
 * @av: arguments passed
 * Return: 0 on success
 */
int main(void)
{
	char user_command[127];
	char *commands[10];
	int num_commands;
	int i;

	while (1)
	{
		display_prompt();
		read_input(user_command, sizeof(user_command));
		num_commands = split_commands(user_command, commands);

		for (i = 0; i < num_commands; ++i)
		{
			process_command(commands[i]);
		}
	}
	return (0);
}
