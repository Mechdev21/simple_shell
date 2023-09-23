#include "main.h"
/**
 * execute - uses execve to execute a command
 * @argv: cmd to eecute
 * Return: nothing
 */
void _execute(char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
