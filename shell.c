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

/**
 * main- the shell
 * @ac: number of argument passed
 * @av: arguments passed
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	char **argv;
	char *cmd = NULL; /* initialize to NULL*/
	size_t l = 0; /* initialize to 0*/
	pid_t child_pid;
	ssize_t len;
	int status;

	if (ac > 1)
	{

		child_pid = fork();
		execute_cmd(av, child_pid, &status, 0);
	}
	prompt(0);
	while ((len = getline(&cmd, &l, stdin)) != -1)
	{
		if (*cmd == '\n') /*usr presses enter*/
			continue; /*do nothing*/
		argv = split_string(cmd, len); /*take command to argv*/
		child_pid = fork();

		if (child_pid == -1)
			continue;
		execute_cmd(argv, child_pid, &status, 1);
		prompt(0);
		free(cmd);
		cmd = 0;
		free_av(argv);
		l = 0; /* reset to 0*/
	}
	free(cmd); /* free the last line*/
	return (0);
}
