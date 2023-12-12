#include "shell.h"

/**
 * change_directory - changes the current directory of the process
 * @path: the directory to change to
 */
void change_directory(const char *path)
{
	char current_path[PATH_MAX];

	/* If no argument is given, change to the home directory */
	if (path == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			perror("cd");
			return;
		}
	}
	/* Save the current working directory */
	if (getcwd(current_path, sizeof(current_path)) == NULL)
	{
		perror("getcwd");
		return;
	}
	/* Change to the specified directory */
	if (chdir(path) == -1)
	{
		perror("cd");
		return;
	}
	/* Update the PWD environment variable */
	if (set_environment_variable("PWD", current_path) == -1)
	{
		perror("setenv");
		return;
	}
}

/**
 * exit_shell - exits the shell
 * @status: prints the exit status
 */
void exit_shell(int status)
{
	my_printf("Exiting shell with status %d.\n", status);
	exit(status);
}

/**
 * print_environment - prints the current environment variables
 */
void print_environment(void)
{
	int index = 0;

	while (environ[index] != NULL)
	{
		my_printf("%s\n", environ[index]);
		index++;
	}
}

/**
 * set_environment_variable - sets or updates an environment variable
 * @variable: the name of the environment variable
 * @value: the value to set for the environment variable
 * Return: 0 on success, -1 on failure
 */
int set_environment_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * unset_environment_variable - unsets an environment variable
 * @variable: the name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int unset_environment_variable(const char *variable)
{
	if (unsetenv(variable) == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
