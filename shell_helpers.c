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
	char *s, *str = NULL;

	while(ls)
	{
		if (ls->str)
		{
			s = _strcat(ls->str, "/");
			str = _strcat(s, cmd);
		}
		if(str && (stat(str, &st) == 0))
		{
			return (str);
		}
		ls = ls->next;
	}
	free(s);
	free(str);
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
		free_list(ls);
		printf("Not Found\n");
		_setenv("PATH", "/usr:/usr/sbin:/usr/local/sbin:/bin", 1);
		return (0);
	}

	if (pid == 0)
	{
		if (flag && (execve(str, av, environ)== -1))
		{
			perror(0);
		}

		else if (!flag && (execve(str, av + 1, environ) == -1))
		{
			perror(0);
		}

		exit(1);
	}
	else
	{
		wait(status);
		if (!s1 && !s)
			free(str);
		free_list(ls);
		_setenv("PATH", "/usr:/usr/sbin:/usr/local/sbin:/bin", 1);
	}
	return (0);
}
