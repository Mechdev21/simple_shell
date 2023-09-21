#include "main.h"
/**
 * _printf - print strings and ints
 * @format: args
 * Return: length of all characters
 */
int _printf(const char *format, ...)
{
form types[] = {{"c", _pchar}, {"s", _pstr}, {"d", _pint}, {"i", _pint}, {NULL, NULL}};
	va_list arguments;
	int pos = 0, length = 0, pos_form;

	va_start(arguments, format);
	if (!format || !format[pos])
		return (-1);
	for (; format[pos]; pos++)
	{
		if (format[pos] == '%')
		{
			if (format[pos + 1] == '\0')
				return (-1);
			if (format[pos + 1] == '%')
				_putchar(37), length++;
			else
			{
				for (pos_form = 0; types[pos_form].ch != NULL; pos_form++)
				{
					if (types[pos_form].ch[0] == format[pos + 1])
					{
						length += types[pos_form].func(arguments);
						break;
					}
				}
				if (types[pos_form].ch == NULL)
				{
					_putchar(format[pos]);
					_putchar(format[pos + 1]), length += 2;
				}
			}
			pos++;
		}
		else
			_putchar(format[pos]), length++;
	}
	va_end(arguments);
	return  (length);
}

/**
 * _strcat - concatenate directories with the 1st position of the array
 * @directory: directories
 * @slash: /
 * @arg: array of commands.
 * Return: str
 **/
char *_strcat(char *directory, char *slash, char *arg)
{
	char *str = NULL;
	int l1, l2, i, k;

	l1 = _strlen(directory);
	l2 = _strlen(arg);
	str = malloc(sizeof(char) * (l1 + l2 + 2));
	if (!str)
		return (NULL);
	for (i = 0; directory[i]; i++)
		str[i] = directory[i];
	str[i] = *slash;
	k = i + 1;
	for (i = 0; arg[i]; i++)
		str[k + i] = arg[i];
	str[k + i] = '\0';
	return (str);
}
