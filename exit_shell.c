#include "shell.h"

/**
 * handle_exit - Handles the exit command
 * @command: The exit command
 */
void handle_exit(char *command)
{
	int status = atoi(command + 5);

	exit_shell(status);
}

