#include "shell.h"

/**
 * main - entry point for the shell program
 * Return: Always 0 on success
 */
int main(void)
{
	char usr_cmd[127];
	char *cmds[10];
	int cmd_count;
	int i;

	while (1)
	{
		display_prompt();

		get_input(usr_cmd, sizeof(usr_cmd));

		cmd_count = split_str(usr_cmd, cmds);

		for (i = 0; i < cmd_count; ++i)
			process_cmd(cmds[i]);
	}

	return (0);
}

