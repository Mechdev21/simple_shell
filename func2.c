#include "main.h"
/**
 * _funcexit - function to exit shell
 * @cmdline: argument from command line
 * Return: 0 on success and 1 on failure
 **/
int _funcexit(char *cmdline)
{
	char *exit_shell = "exit";
	int a = 0;
	int lenght = _strlen(cmdline);

	if(lenght == 4)
	{
		while(exit_shell[a])
		{
			if(exit_shell[a] != cmdline[a])
				return (1);
			a++;
		}
		free(cmdline);
		return (0);
	}
	return (1);
}
/**
 * check_id - check for CTRL + C signal
 * @cue: sheck_id parameter
 **/
void check_id(int cue)
{
	signal(cue, SIG_IGN);
	write(STDOUT_FILENO, "\n#cprogram$ ", 14);
	signal(SIGINT, check_id);
}
