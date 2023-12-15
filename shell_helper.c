#include "shell.h"

/**
 * spath- searches for cmd file
 *
 * @cmd: input command
 * @ls: input path list
 *
 * Return: pointer found path on sucess, NULL otherwise
 */
char *spath(char *cmd, list_t *ls)
{
	struct stat st;
	char *str;

	while (ls)
	{
		if (ls->str)
		{
			str = _strcat(ls->str, "/");
			str = _strcat(str, cmd);
		}
		if (stat(str, &st) == 0)
			return (str);

		ls = ls->next;
	}
	printf("kael\n");
	return (0);
}
/**
 * _execvep- executes with path
 *
 * @av: input argument
 * @cmd: input string
 * @ls: input list of paths
 *
 * Return: -1 if fail
 */
int _execvep(char **av, char *cmd)
{
	list_t *ls = mklist("PATH");
	char *str = spath(cmd, ls);
	pid_t pid;
	int status;

	if (str)
	{
		pid = fork();
		if (pid == 0)
		{
			if ((execve(str, av, environ)) == -1)
				perror(0);
			exit(1);
		}

		else
		{
			wait(&status);
			free_list(ls);
			return (0);
		}
	}
	free_list(ls);
	return (-1);
}

/**
 * process_cmd- gets command
 * @ls: input list
 *
 * Return: non zero on success
 */
int process_cmd(list_t *ls)
{
	char *cmd, **av;
	size_t len;

	prompt(0);
	if ((getline(&cmd, &len, stdin)) != -1)
	{
		if (*cmd == '\n')
		{
			prompt(0);
			return (1);
		}
		av = split_string(cmd);
		_execvep(av, av[0]);

	}
	free_av(av);
	free(cmd);
	cmd = NULL;
	return (1);
}
