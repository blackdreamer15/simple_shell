#include "shell.h"

/**
 * process_cmd - Processes individual shell commands
 * @cmd: The command to be processed
 */
void process_cmd(char *cmd)
{
	if (_strncmp(cmd, "exit", 4) == 0)
		handle_exit(cmd);

	else if (_strncmp(cmd, "env", 3) == 0)
		print_environment();

	else if (_strncmp(cmd, "setenv", 6) == 0)
		handle_setenv(cmd);

	else if (_strncmp(cmd, "unsetenv", 8) == 0)
		handle_unsetenv(cmd);

	else if (_strncmp(cmd, "cd", 2) == 0)
	{
		char *path = _strtok(cmd + 3, " ");

		change_dir(path);
	}

	else
		execute_prompt(cmd);
}

/**
 * exec_cmd_with_args - executes a command with arguments
 * @cmd: the command to be executed
 */
void exec_cmd_with_args(const char *cmd)
{
	char *args[170];
	int argc = 0;
	char *tokenized_cmd = _strtok((char *)cmd, " ");

	while (tokenized_cmd != NULL)
	{
		args[argc++] = tokenized_cmd;
		tokenized_cmd = _strtok(NULL, " ");
	}

	args[argc] = NULL;

	if (execvp(args[0], args) == -1)
		perror("bash");
}

/**
 * exec_cmd - executes a command with arguments
 * @cmd: the command to be executed
*/
void exec_cmd(const char *cmd)
{
	char *args[170];
	int argc = 0;
	char *tokenized_cmd = _strtok((char *)cmd, " ");

	while (tokenized_cmd != NULL)
	{
		args[argc++] = tokenized_cmd;
		tokenized_cmd = _strtok(NULL, " ");
	}

	args[argc] = NULL;

	if (cmd_in_path_checker(args[0]))
	{
		pid_t process_pid = fork();

		if (process_pid == -1)
		{
			_printf("Forking error...\n");
			exit(EXIT_FAILURE);
		}
		else if (process_pid == 0)
		{
			/* Child process */
			if (execvp(args[0], args) == -1)
				perror("bash");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			wait(NULL);
		}
	}
	else
		_printf("bash: %s: command not found\n", args[0]);
}


/**
 * cmd_in_path_checker - checks if a command exists in the PATH
 * @cmd: the command to be checked
 * Return: 1 if the command exists, 0 otherwise
*/
int cmd_in_path_checker(const char *cmd)
{
	char *path;
	char *path_copy;
	char *token;

	if (access(cmd, F_OK) == 0)
		return (1);

	path = getenv("PATH");
	path_copy = strdup(path);
	token = _strtok(path_copy, ":");

	while (token != NULL)
	{
		char cmd_path[256];

		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			free(path_copy);
			return (1);
		}
		token = _strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}

