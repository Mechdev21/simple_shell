#include "main.h"
/**
 * _findcha -find each charcter in a command line
 * Return: cmd
 **/
int _findcha()
{
	static unsigned char bufer[300];
	static int position;
	static int number;

	position = 0;
	number = 0;
	if(position >= number)
	{
		position = 0;
		number = read(STDIN_FILENO, bufer,300);
		_printf("%i\n", number);
		if(number == 0)
			return (EOF);
		if (number < 0)
			return (EOF);
	}
	return (bufer[position++]);
}
/**
 * find_path - finds argument in a path
 * @argv: argument string
 * Return: argument string
 */
char *find_path(char *argv)
{
	if(access(argv, X_OK) == 0)
		return (argv);
	return (NULL);
}

/**
 * exec_cmd - find if argument exist in a path
 * @argv: argument strings
 * Return: argmunet string
 */
char *exec_cmd(char *argv)
{
	shell_t *head = NULL;
	char *buf = NULL;
	char *point = NULL;

	point = _findenv("PATH");
	head = _chain(point);
	buf = _search(&head, argv);
	if (buf != NULL)
	{
		free(point),
		free_list(head);
		return (buf);
	}
	free(point);
	free_list(head);
	return (NULL);
}
