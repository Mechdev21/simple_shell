#include "main.h"
/**
 * _strlen: counts the length of a string
 * @c: character to count
 * Return: number of string counted
 */
int _strlen(char *c)
{
	int i;

	for (i = 0; c[i]; i++)
		;
	return (i);
}

/**
 * _strtok - reduces a string into tokens
 * @str: string
 * @delim: character that helps break string into tokens
 * Return: NULL if fails or pointer to the tokenized string
 */
char *_strtok(char *str, char *delim)
{
	int i = 0, j = 0, a = 0;
	static char *follow;

	if (!delim || (!str && !follow))
		return (NULL);
	str == NULL ? str = follow : str;
	for (; str[j] == ' ' ; j++)
	{
		if (str[j + 1] == '\0')
			return (NULL);
	}
	for (i = j ; str[i] != '\0' ; i++)
	{
		if (str[i] == *delim)
		{
			a = 1;
			break;
		}
	}
	for (; str[i] != '\0' ; i++)
		if (str[i] != delim[0])
			break;
		else if (str[i + 1] == '\0')
		{
			a = 0, str[i] = '\0';
			break;
		}
		else
			str[i] = '\0';
	if (a == 0)
	{
		follow = NULL;
		return (str + j);
	}
	if (str + i)
		follow = str + i;
	else
		follow = NULL;
	return (str + j);
}
/**
 * *_strcpy - copy a string from a source to another destination
 * @src: original string to copy from
 * @dest: destination to copy into
 * Return: return a pointer char
 */
char *_strcpy(char *dest, char *src)
{
	int i, j;

	for (i = 0; src[i] != '\0' ; i++)
	{
	}
	for (j = 0; j < i ; j++)
	{
		dest[j] = src[j];
	}
	for (; j <= i ; j++)
	{
		dest[j] = '\0';
	}
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @src: source of the string to duplicate
 * Return: the duplicated string
 */
char *_strdup(char *src)
{
	char *str;
	char *p;
	int len = 0;

	while (src[len])
		len++;
	str = malloc(len + 1);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}
