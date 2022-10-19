#include "main.h"

/**
 * print_int - prints an int from a va_list object type
 *
 * @args: the va_list object
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int i, s;

	s = va_arg(args, int);

	i = print_num(s);

	return (i);
}

/**
 * print_num - prints a number
 *
 * @num: the number to be printed
 * Return: the nunmber of characters printed
 */
int print_num(int num)
{
	int length = 0;

	if (num < 0)
	{
		length += _putchar('-');
		num = -num;
	}

	if (num / 10)
		length += print_num((num / 10));

	length += _putchar((num % 10) + '0');
	return (length);
}
