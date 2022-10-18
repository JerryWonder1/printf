#include "main.h"

/**
 * print_char - prints a single character from a va_list object type
 *
 * @args: the va_list object
 * Return: 1
 */
int print_char(va_list args)
{
	char s;

	s = va_arg(args, int);

	_putchar(s);

	return (1);
}
