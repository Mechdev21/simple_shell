#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _pchar - writes to stdout
 * @args: The character to print
 * Return: integer.
 */
int _pchar(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
/**
* _pint - write an int to stdout.
* @args: arguments
* Return: Int
*/
int _pint(va_list args)
{
	long int a, b, c = 1, d;
	int counter = 0;

	a = va_arg(args, int);

	if (a < 0)
	{
		b = -a;
		_putchar('-');
		counter++;
	}
	else
		b = a;
	d = b;
	while (b > 9)
	{
		b = b / 10;
		c *= 10;
	}
	while (c > 0)
	{
		_putchar(((d / c) % 10) + '0');
		counter++;
		c /= 10;
	}
	return (counter);
}
/**
 * _pstr - prit string
 * @args: arguments
 * Return: Int
 */
int _pstr(va_list args)
{
	char *i;
	int j;

	i = va_arg(args, char *);
	if (i == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (j = 0 ; i[j] != '\0' ; j++)
	{
	_putchar(i[j]);
	}
	return (j);
}

