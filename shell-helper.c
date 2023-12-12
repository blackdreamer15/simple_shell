#include "shell.h"

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
		if (flag && (execve(av[0], av, environ)) == -1)
		{
			sprintf(cmd, "bash: %s", av[0]);
			perror(cmd);
		}

		else if (!flag && (execve(av[1], av + 1, environ)) == -1)
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
