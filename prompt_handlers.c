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
 * execute_prompt - executes the prompt from user
 * @prompt: the command to be executed
 * Return:void
 */
void execute_prompt(const char *prompt)
{
		execute_command(prompt);
}

/**
 * read_input - gets prompt as input from users
 * @input: the command to executed
 * @size_of_input: size of the prompt
 * Return: void
 */
void read_input(char *input, size_t size_of_input)
{
	if (fgets(input, size_of_input, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_printf("Input Error.\n");
			exit(EXIT_FAILURE);
		}
	}

	input[strcspn(input, "\n")] = '\0';
}

