#include "shell.h"

/**
 * handle_setenv - Handles the setenv command
 * by parsing the input and calling set_environment_variable
 * @command: The input command containing the setenv parameters
 */

void handle_setenv(const char *command)
{
	char *variable = my_strtok((char *)command + 7, " ");
	char *value = my_strtok(NULL, " ");

	if (variable && value)
	{
		if (set_environment_variable(variable, value) == -1)
		{
			write(STDERR_FILENO, "Failed to set environment variable.\n", 36);
		}
	}
	else
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
	}
}

/**
 * handle_unsetenv - Handles the unsetenv command
 * by parsing the input and calling unset_environment_variable
 * @command: The input command containing the unsetenv parameters
 */

void handle_unsetenv(const char *command)
{
	char *variable = my_strtok((char *)command + 9, " ");

	if (variable)
	{
		if (unset_environment_variable(variable) == -1)
			write(STDERR_FILENO, "Failed to unset environment variable.\n", 38);
	}
	else
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
}
