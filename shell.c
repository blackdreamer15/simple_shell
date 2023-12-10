#include "shell.h"

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
	size_t len = 0;	  /* initialize to 0*/
	ssize_t nread;
	pid_t child_pid;
	int status;

	if (ac > 1)
	{
		child_pid = fork();
		execute_cmd(av, child_pid, &status, 0);
	}

	prompt(0);

	while ((nread = getline(&cmd, &len, stdin)) != -1)
	{
		if (*cmd == '\n') /*usr presses enter*/
			continue;	  /*do nothing*/

		argv = split_string(cmd); /*take command to argv*/
		child_pid = fork();

		if (child_pid == -1)
			continue;

		execute_cmd(argv, child_pid, &status, 1);
		prompt(0);
		free(cmd);
		free_av(argv);
		cmd = 0;
		len = 0; /* reset to 0*/
	}
	free(cmd);
	return (0);
}
