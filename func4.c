#include "main.h"
/**
 * _getline - read line from prompt
 * @buf: buf to read into
 * @size: size f buffer
 * @stream: source where the string is read from
 * Return: the number of bytes read into the buffer
 **/
ssize_t _getline(char **buf, size_t *size, FILE *stream)
{
	size_t count = 0;
	size_t space = 1024;
	char a;

	if (!buf || !size || !stream)
		return (-1);
	if (*buf == NULL)
	{
		*buf = malloc(space);
		if (!(*buf))
			return (-1);
	}
	while ((a = _findcha()) != EOF)
	{
		if (a == '\n')
		{
			count++;
			break;
		}
		count++;
		(*buf)[count - 1] = a;
	}
	if (a == EOF)
	{
		return (-1);
	}
	(*buf)[count] = '\0';
	return (count);
}
/**
* linetoken - split line from the prompt
* @cmd_line: string of cmd
* Return: a pointer to string to command line
**/
char **linetoken(char *cmd_line)
{
	char **strptr;
	int size = 100;
	int index = 0;
	char *line;

	strptr = malloc(sizeof(char *) * size);
	if (strptr == NULL)
		exit(EXIT_FAILURE);
	line = _strtok(cmd_line, " ");
	while (line != NULL)
	{
		strptr[index++] = line;
		line = _strtok(NULL, " ");
	}
	strptr[index] = NULL;
	return (strptr);
}
