#include "shell.h"

/**
 * display_prompt - displays the shell prompt
 * Return: void
 */
void display_prompt(void)
{
	_printf("$ ");
}

/**
 * execute_prompt - executes the shell prompt
 * @cmd: the command to be executed
 * Return: void
 */
void execute_prompt(const char *cmd)
{
		exec_cmd(cmd);
}

/**
 * get_input - gets prompt as input from users
 * @input: the command to executed
 * @input_size: size of the prompt
 * Return: void
 */
void get_input(char *input, size_t input_size)
{
	if (fgets(input, input_size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_printf("Input Error...\n");
			exit(EXIT_FAILURE);
		}
	}

	input[strcspn(input, "\n")] = '\0';
}

