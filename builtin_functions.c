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
