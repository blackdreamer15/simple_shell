#include "shell.h"

/**
 * spath-serches path
 * @ls: input list of path
 *
 * Return: 0 if found
 */
char *spath(list_t *ls, char *cmd)
{
	struct stat st;
	char *s, *str;

	while(ls)
	{
		if (ls->str)
		{
			str = _strcat(ls->str, "/");
			str = _strcat(str, cmd);
		}
		if(str && (stat(str, &st) == 0))
		{
			return (str);
		}
		ls = ls->next;
	}
	return(0);
}

/**
 * _execvp- executes command
 * @av: input command
 *
 * @flag: flag
 * @status: status
 *
 * Return: 0 on success
 */
int _execvp(char **av, int *status, int flag)
{
	list_t *ls;
	pid_t pid;
	char *cmd = "Erro";
	char *str, *s, *s1;

	if ((ls = mklist("PATH")) == NULL)
		return (-1);
	if (flag && ((s = _strchr(av[0], '/')) != 0))
		str = av[0];
	else if (!flag && ((s1 = _strchr(av[1], '/')) != 0))
		str = av[1];
	else if (flag)
		str = spath(ls, av[0]);
	else
		str = spath(ls, av[1]);

	if (str)
		pid = fork();
	else
	{
		printf("Not Found\n");
		return (0);
	}

	if (pid == 0)
	{
		if (flag && (execve(str, av, environ)== -1))
		{
			perror(cmd);
		}

		else if (!flag && (execve(str, av + 1, environ) == -1))
		{
			perror(cmd);
		}

		exit(1);
	}
	else
	{
		wait(status);
		if (!s1 && !s)
		{
			free(ls);
			free(str);
		}
		_setenv("PATH", "/usr:/usr/sbin:/usr/local/sbin:/bin", 1);

	}
	return (0);
}
