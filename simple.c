#include "main.h"
/**
 * main - Entry poin
 * @argc: arguments counts
 * @argv: arguments vector
 * @env: enviromet
 * Return: always 0
 */
int main(int __attribute__((unused))argc, char **argv, char **env)
{
	int stat_pos = 0, read_line = 1, count = 0;

	while (read_line)
	{
		char *cmdline = NULL, **argline = NULL;
		size_t line_size = 0;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cprogramme$ ", 13);
		signal(SIGINT, check_id);
		read_line = getline(&cmdline, &line_size, stdin);
		if (read_line < 0)
		{
			free(cmdline);
			exit(stat_pos);
		}
		if (read_line == 1)
		{
			free(cmdline);
			continue;
		}
		if (read_line != EOF)
		{
			count++;
			_strtok(cmdline, "\n");
			if (_funcexit(cmdline) == 0)
				return (stat_pos);
			if (_shellenv(cmdline, count, argv, env) == 0)
				continue;
			argline = linetoken(cmdline);
			if (argline[0] == NULL)
			{
				free(cmdline), free(argline);
				continue;
			}
			stat_pos = execute_cmd(argline, argv, count);
		}
		free(cmdline), free(argline);
	}
	return (stat_pos);
}
