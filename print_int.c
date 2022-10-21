#include "main.h"

/**
 * print_int - writes an int from a va_list object type to a buffer
 *
 * @args: the va_list object
 * @buffer: the buffer to write to
 * Return: number of characters printed
 */
int print_int(va_list args, char *buffer)
{
	int i, s;

	s = va_arg(args, long int);

	i = print_num(s, buffer);

	return (i);
}

/**
 * print_num - writes a number to buffer
 *
 * @num: the number to be printed
 * @buffer: the buffer to write to
 * Return: the number of characters printed
 */
int print_num(long int num, char *buffer)
{
	int length = 0;

	if (num < 0)
	{
		add_to_buffer('-', buffer);
		length++;
		num = -num;
	}

	if (num / 10)
		length += print_num((num / 10), buffer);

	add_to_buffer((num % 10) + '0', buffer);
	length++;
	return (length);
}
