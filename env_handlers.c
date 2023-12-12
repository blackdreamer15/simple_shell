#include "shell.h"

/**
 * handle_setenv - Handles the setenv command by parsing
 *		   the input and calling set_env_var
 * @cmd: The input command containing the setenv parameters
 */
void handle_setenv(const char *cmd)
{
	char *var = _strtok((char *)cmd + 7, " ");
	char *val = _strtok(NULL, " ");

	if (var && val)
	{
		if (set_env_var(var, val) == -1)
			write(STDERR_FILENO, "Failed to set environment variable.\n", 36);
	}
	else
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
}

/**
 * handle_unsetenv - Handles the unsetenv command by parsing
 *		     the input and calling unset_env_var
 * @cmd: The input command containing the unsetenv parameters
 */
void handle_unsetenv(const char *cmd)
{
	char *var = _strtok((char *)cmd + 9, " ");

	if (var)
	{
		if (unset_env_var(var) == -1)
			write(STDERR_FILENO, "Failure while unsetting environment variable.\n", 38);
	}
	else
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
}

