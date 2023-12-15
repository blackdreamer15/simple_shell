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
	char *str = NULL, cwd[1024];

	if (stat(cmd, &st) == 0)
		return (cmd);

	if (*cmd == '.')
	{
		getcwd(cwd, 1024);
		str = _strcat(cwd, (cmd + 1));
		if (stat(str, &st) == 0)
			return (cmd + 2);
		_perror(cmd);
		return (0);
	}
	if (_strchr(cmd, '/') != 0)
	{
		if (stat(str, &st) == 0)
			return (cmd);
		_perror(cmd);
		return (0);
	}
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

	if (_strchr(cmd, '/') != 0)
		return (cmd);
	_perror(cmd);
	return (0);
}
/**
 * _execvep- executes with path
 *
 * @av: input argument
 * @cmd: input
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
 *
 *
 * Return: non zero on success
 */
int process_cmd(void)
{
	char *cmd, **av;
	size_t len;

	prompt("#");
	if (getline(&cmd, &len, stdin) != -1)
	{
		if (*cmd == '\n')
		{
			return (1);
		}
		av = split_string(cmd);
		_execvep(av, av[0]);
	}
	else
	{
		_putchar('\n');
		exit(0);
	}

	free_av(av);
	free(cmd);
	cmd = NULL;
	return (1);
}