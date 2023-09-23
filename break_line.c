#include "main.h"
/**
 * tokenz - used to break our strings into tokens
 * @argc: used to keep counnt of words to be tokenised
 * @read: words to be tokensized
 * @delim: character to break strings
 * Return: tokenized strings
 */
char **tokenz(int *argc, char *read, char *delim)
{
	char *token;
	char **tok;
	int i;

	char *copy_read = _strdup(read);

	_strcpy(copy_read, read);
	token = _strtok(read, delim);
	(*argc)++;
	while (token)
	{
		(*argc)++;
		token = _strtok(NULL, delim);
	}
	tok = malloc(sizeof(char *) * (*argc));
	token = _strtok(copy_read, delim);
	for (i = 0; token; i++)
	{
		tok[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(tok[i], token);
		token = _strtok(NULL, delim);
	}
	tok[i] = NULL;
	return (tok);
}
