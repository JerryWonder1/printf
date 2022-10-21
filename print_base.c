#include "main.h"


/**
 * print_base10 - writes an int from a va_list object type in base ten form
 *                to a buffer
 *
 * @args: the va_list object
 * @buffer: buffer to be written to
 * Return: number of characters printed
 */
int print_base10(va_list args, char *buffer)
{
	unsigned long int s;
	unsigned int i;

	s = va_arg(args, unsigned long int);

	i = print_num(s, buffer);

	return (i);
}

/**
 * print_base2 - writes an int from a va_list object type in base two form
 *               to a buffer
 *
 * @args: the va_list object
 * @buffer: buffer to write to
 * Return: number of characters printed
 */
int print_base2(va_list args, char *buffer)
{
	unsigned long int s;
	unsigned int i, base;
	char caps;

	base = 2;
	caps = 'n';

	s = va_arg(args, unsigned long int);

	i = print_in_base(s, base, &caps, buffer);

	return (i);
}

/**
 * print_base8 - writes an int from a va_list object type in base eight form
 *               to a buffer
 *
 * @args: the va_list object
 * @buffer: buffer to write to
 * Return: number of characters printed
 */
int print_base8(va_list args, char *buffer)
{
	unsigned long int s;
	unsigned int i, base;
	char caps;

	base = 8;
	caps = 'n';

	s = va_arg(args, unsigned long int);

	i = print_in_base(s, base, &caps, buffer);

	return (i);
}

/**
 * print_in_baseX - writes a number in base hexadecimal to a buffer
 *                  use capital letters for number substitutions
 *
 * @args: the va_list object
 * @buffer: the buffer to be written to
 * Return: the number of characters printed
 */
int print_in_baseX(va_list args, char *buffer)
{
	unsigned long int s;
	unsigned int i, base;
	char caps;

	base = 16;
	caps = 'y';

	s = va_arg(args, unsigned int);

	i = print_in_base(s, base, &caps, buffer);

	return (i);
}

/**
 * print_in_basex - writes a number in base hexadecimal to a buffer
 *                  use lowercase letters for number substitutions
 *
 * @args: the va_list object
 * @buffer: the buffer to be written to
 * Return: the number of characters printed
 */
int print_in_basex(va_list args, char *buffer)
{
	unsigned long int s;
	unsigned int i, base;
	char caps;

	base = 16;
	caps = 'n';

	s = va_arg(args, unsigned int);

	i = print_in_base(s, base, &caps, buffer);

	return (i);
}
