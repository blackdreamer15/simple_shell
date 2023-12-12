#include "shell.h"

/**
 * display_prompt - displays the shell promp
 */
void display_prompt(void)
{
	my_printf("$ ");
}

/**
 * execute_prompt - executes the prompt from user
 * @prompt: the command to be executed
 *
 */
void execute_prompt(const char *prompt)
{
		execute_command(prompt);
}

/**
 * read_input - gets prompt as input from users
 * @input: the command to executed
 * @size_of_input: size of the prompt
 *
 */
void read_input(char *input, size_t size_of_input)
{
	if (fgets(input, size_of_input, stdin) == NULL)
	{
		if (feof(stdin))
		{
			my_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			my_printf("Input Error.\n");
			exit(EXIT_FAILURE);
		}
	}

	input[strcspn(input, "\n")] = '\0';
}
