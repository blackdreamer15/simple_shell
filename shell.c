#include "shell.h"

int _count = 0;
/**
 * main- the shell
 * @ac: number of argument passed
 * @av: arguments passed
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	list_t *ls = mklist("PATH");

	if (ac > 1)
	{
		_count++;
		_execvep(av + 1, av[1]);
	}
	while (1)
	{
		_count++;
		process_cmd();
	}
	free_list(ls);
}
