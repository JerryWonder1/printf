#include "main.h"

/**
 * print_string - prints a string from a va_list object type
 *
 * @args: the va_list object
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	int i;
	char *s;

	s = va_arg(args, char *);

	for (i = 0; s[i]; i++)
		_putchar(s[i]);

	return (i);
}
