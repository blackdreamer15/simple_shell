#include "shell.h"

/**
 * main- the shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char **argv;
	char *cmd;
	size_t l;
	pid_t child_pid;
	ssize_t len;
	int status;

	printf("#shell$ "); /*prompt*/
	while ((len = getline(&cmd, &l, stdin)) != -1)
	{
		if (*cmd == '\n') /*usr presses enter*/
			continue; /*do nothing*/
		argv = split_string(cmd, len); /*take command to argv*/

		child_pid = fork();
		if (child_pid == 0)
		{
			if ((execve(argv[0], argv, environ)) == -1)
			{
				sprintf(cmd, "bash: %s", argv[0]);
				perror(cmd);
			}
			exit(1);
		}
		else
		{
			wait(&status);
			printf("#shells$ ");
		}
	}
	return (0);
}
