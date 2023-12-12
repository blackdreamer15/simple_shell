#include "shell.h"

/**
 * spath-serches path
 * @ls: input list of path
 *
 * Return: 0 if found
 */
char *spath(list_t *ls)
{
	struct stat st;

	while(ls)
	{
		if(stat(ls->str, &st) == 0)
			return (ls->str);
		else
			continue;
		ls++;
	}
	return(0);
}

/**
 * _execvp- executes with path specified
 *
 * @av: input commmand
 * Return: 0 success
 */
int _execvp(char **av)
{
	char *str, *path;

	str = _getenv("PATH");
	path = _strcat(str, "/usr/bin:/bin");
	printf("%s\n", path);
	_setenv("PATH", "/usr/bin:/bin", 1);
	printf("%s\n", _getenv("PATH"));
	if ((execve(av[0], av, environ)) == -1)
		return (-1);
}


/**
 * execute_cmd- executes command
 * @av: input command
 * @pid: current process id
 * @flag: flag
 * @status: status
 *
 * Return: 0 on success
 */
int execute_cmd(char **av, pid_t pid, int *status, int flag)
{
	char *cmd = malloc(sizeof(char) * (strlen(av[0]) + 7));

	if (pid == 0)
	{
		if (flag && _execvp(av) == -1)
		{
			sprintf(cmd, "bash: %s", av[0]);
			perror(cmd);
		}

		else if (!flag && _execvp(&av[1]) == -1)
		{
			sprintf(cmd, "bash: %s", av[1]);
			perror(cmd);
		}

		exit(1);
	}
	else
	{
		wait(status);
		free(cmd);
	}

	if (flag)
		return (0);
	return (1);
}
