#include "main.h"
/**
 * main - entry point of the programme
 *
 * Return: zero
 */
int main(void)
{
	while(1)
	{
		int argc = 0;
		char *delim = " \n";
		char *line;
		char **argv;

		printf("$ ");
		line = read_input();
		argv = tokenz(&argc, line, delim);
		_execute(argv);
		free(line);
	}

	return (0);
}
