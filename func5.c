#include "main.h"
/**
 * execute_cmd - helps execute the shell process
 * @argcmd: arguments from command_line
 * @argv: argument of string
 * @count: number of agument processed
 * Return: 0 on success
 **/
int execute_cmd(char **argcmd, char **argv, int count)
{
	pid_t child_pid;
    	int stat_pos = 0;
	int stat;
    	char *cmd_path = NULL;
	char *buffer = NULL;

    	cmd_path = find_path(argcmd[0]);
	if (cmd_path == NULL)
	{
		buffer = exec_cmd(argcmd[0]);
		if (buffer == NULL)
		{
			_printf("%s: %d: %s: unknown\n", argv[0], count, argcmd[0]);
			free(buffer);
			return (1);
		}
	}
	child_pid = fork();
	if (child_pid < 0)
		exit(errno);
	else if (child_pid == 0)
	{
		if (cmd_path != NULL)
		{
			if (execve(cmd_path, argcmd, environ) == -1)
				exit(errno);
		}
		if (execve(buffer, argcmd, environ) == -1)
			exit(errno);
	}

	wait(&stat);
	if (WIFEXITED(stat))
		stat_pos = WEXITSTATUS(stat);
	free(buffer);

	return (stat_pos);
}
/**
 * _search- search the direct for command
 * @head: link head
 * @argv: string argument
 * Return: command path
 **/
char *_search(shell_t **head, char *argv)
{
	shell_t *point = *head;
	char *jar;

	if(argv[0] == '.' || argv[0] == '/')
	{
		if (access(argv, X_OK) == 0)
			return (argv);
	}

	while (point)
	{
		jar = _strcat(point->dic, "/", argv);
		if(access(jar, X_OK) == 0)
		{
			return (jar);
		}
		free(jar);
		point = point->next;
	}
	return (NULL);
}
