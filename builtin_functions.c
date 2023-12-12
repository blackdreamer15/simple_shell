#include "shell.h"

/**
 * change_dir - changes the current directory of the process
 * @path: the directory to change to
 */
void change_dir(const char *path)
{
	char curr_path[PATH_MAX];

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
	if (getcwd(curr_path, sizeof(curr_path)) == NULL)
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
	if (set_environment_variable("PWD", curr_path) == -1)
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
	_printf("Exiting shell with status %d.\n", status);
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
		_printf("%s\n", environ[index]);
		index++;
	}
}

/**
 * set_environment_variable - sets or updates an environment variable
 * @var: the name of the environment variable
 * @val: the value to set for the environment variable
 * Return: 0 on success, -1 on failure
 */
int set_environment_variable(const char *var, const char *val)
{
	if (setenv(var, val, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * unset_environment_variable - unsets an environment variable
 * @var: the name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int unset_environment_variable(const char *var)
{
	if (unsetenv(var) == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}

