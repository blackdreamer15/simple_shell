#include "shell.h"

/**
 * process_command - Processes individual shell commands
 * @command: The command to be processed
 */

void process_command(char *command)
{
	if (my_strncmp(command, "exit", 4) == 0)
		handle_exit(command);
	
	else if (my_strncmp(command, "env", 3) == 0)
		print_environment();
	
	else if (my_strncmp(command, "setenv", 6) == 0)
		handle_setenv(command);
	
	else if (my_strncmp(command, "unsetenv", 8) == 0)
		handle_unsetenv(command);
	
	else if (my_strncmp(command, "cd", 2) == 0)
	{
		char *path = my_strtok(command + 3, " ");

		change_directory(path);
	}
	else
		execute_prompt(command);
}
