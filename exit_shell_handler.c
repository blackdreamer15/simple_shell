#include "shell.h"

/**
 * handle_exit - Handles the exit command
 * @cmd: The exit command
 */
void handle_exit(char *cmd)
{
	int status = atoi(cmd + 5);

	exit_shell(status);
}

