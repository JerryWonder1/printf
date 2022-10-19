#include "main.h"

/**
 * print_base2 - prints an int from a va_list object type in base two form
 *
 * @args: the va_list object
 * Return: number of characters printed
 */
int print_base2(va_list args)
{
	int i, s, base;

	base = 2;

	s = va_arg(args, int);

	i = print_in_base(s, base);

	return (i);
}

/**
 * print_in_base - prints a number in base 'base'
 *
 * @num: the number to be printed
 * Return: the number of characters printed
 */
int print_in_base(int num, int base)
{
	int numCopy, numerator, remainder;
	int length = 0;

	if (num < 0)
	{
		length += _putchar('-');
		num = -num;
	}

	numCopy = num;

	while (1)
	{
		numerator = numCopy / base;
		remainder = numCopy % base;

		if (numerator == 0)
			break;
		length += print_num(remainder);

		numCopy = numerator;
	}

	length += print_num(numCopy);

	return (length);
}
