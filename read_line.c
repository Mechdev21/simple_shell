#include "main.h"

/**
 * read_input - reads from stdin
 * @line: buffer to raed into
 * @read: amout of character raed
 * @n: size of line
 * Return: pointer to buffer
 */

char* read_input()
{
	char *line;
	size_t n = 1024;
	ssize_t read;

	line = malloc(sizeof(char) * n);

	read = getline(&line, &n, stdin);
	if(read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
