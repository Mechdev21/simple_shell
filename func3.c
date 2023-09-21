#include "main.h"
/**
 * _shellenv - print the Path of the enviroment
 * @cmdline: commad line parametr
 * @count: tracks the number of entry
 * @argline: main argument
 * @path: main enviroment path
 * Return: 0 if succesfull
 **/
int _shellenv(char *cmdline, int count, char **argline, char **path)
{
	char *path_line = "env";
	int a = 0;
	int lenght = _strlen(cmdline);

	if (lenght == 3)
	{
		while (path_line[a])
		{
			if (path_line[a] != cmdline[a])
				return (1);
			a++;
		}
		if (path)
		{
			for (a = 0; path[a] != NULL; a++)
				_printf("%s\n", path[a]);
			free(cmdline);
			return (0);
		}
		else
		{
			_printf("%s: %d: env_path: unknown env\n", argline[0], count);
			return (127);
		}
	}
	return (1);
}
/**
 * _findenv - find the name of the enviroment
 * @env_name: enviroment name
 * Return: pointer to the enviroment var
 */
char *_findenv(const char *env_name)
{
	int a;
	int b;
	char *c;
	char *dup;

	for (a = 0 ; environ[a] != NULL ; a++)
	{
		for (b = 0 ; env_name[b] == environ[a][b] && env_name[b] != '\0' ; b++)
		{
			if (env_name[b + 1] == '\0')
			{
				c = &environ[a][b + 2];
				dup = malloc(sizeof(char) * _strlen(c) + 1);

				if (!dup)
					return (NULL);

				dup = _strcpy(dup, c);
				return (dup);
			}
		}
	}
	return (NULL);
}
