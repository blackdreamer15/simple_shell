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
	int status;

	if (ac > 1)
	{
		_execvp(av, &status, 0);
	}

	prompt(0);

	while ((nread = getline(&cmd, &len, stdin)) != -1)
	{
		if (*cmd == '\n')
		{
			prompt(0);
			continue;
		}

		argv = split_string(cmd); /*take command to argv*/

		_execvp(argv, &status, 1);
		prompt(0);
		free(cmd);
		free_av(argv);
		cmd = 0;
		len = 0; /* reset to 0*/
	}
	free(cmd);
	return (0);
}
