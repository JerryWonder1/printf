#include "main.h"

/**
 * print_base2 - prints an int from a va_list object type in base two form
 *
 * @args: the va_list object
 * Return: number of characters printed
 */
int print_base2(va_list args)
{
	unsigned int i, s, base;
	char caps;

	base = 2;
	caps = 'n';

	s = va_arg(args, unsigned int);

	i = print_in_base(s, base, &caps);

	return (i);
}

/**
 * print_base8 - prints an int from a va_list object type in base eight form
 *
 * @args: the va_list object
 * Return: number of characters printed
 */
int print_base8(va_list args)
{
	unsigned int i, s, base;
	char caps;

	base = 8;
	caps = 'n';

	s = va_arg(args, unsigned int);

	i = print_in_base(s, base, &caps);

	return (i);
}

/**
 * print_in_base - prints a number in base 'base'
 *
 * @num: the number to be printed
 * @base: the base to convert number to
 * Return: the number of characters printed
 */
int print_in_base(unsigned int num, unsigned int base, char *format)
{
	unsigned int numerator, remainder;
	int length = 0;

	if (num >= base)
	{
		numerator = num / base;
		remainder = num % base;

		length += print_in_base(numerator, base, format);

		if (*format == 'X')
			length += _putchar(substitute_number(remainder, 'y'));
		else
			length += _putchar(substitute_number(remainder, 'n'));
	}
	else
		if (*format == 'X')
			length += _putchar(substitute_number(num, 'y'));
		else
			length += _putchar(substitute_number(num, 'n'));

	return (length);
}

/**
 * substitute_number - substitute a number to letters if greater than 10
 *                     else return the number in char form
 *
 * @num: the number to be transformed
 * @caps: a flag that determines whether to substitute with capital letters or not
 * Return: number in char form or number's substitution
 */
char substitute_number(int num, char caps)
{
	char caps_subs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char subs[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char s;
	if (num > 9)
		s = caps == 'y' ? caps_subs[num - 10] : subs[num - 10];
	else
		s = '0' + num;

	return s;
}

/**
 * print_in_baseX - prints a number in base hexadecimal
 *                  use capital letters for number substitutions
 *
 * @num: the number to be printed
 * Return: the number of characters printed
 */
int print_in_baseX(va_list args)
{
	unsigned int i, s, base;
	char caps;

	base = 16;
	caps = 'y';

	s = va_arg(args, unsigned int);

	i = print_in_base(s, base, &caps);

	return (i);
}

/**
 * print_in_basex - prints a number in base hexadecimal
 *                  use lowercase letters for number substitutions
 *
 * @num: the number to be printed
 * Return: the number of characters printed
 */
int print_in_basex(va_list args)
{
	unsigned int i, s, base;
	char caps;

	base = 16;
	caps = 'n';

	s = va_arg(args, unsigned int);

	i = print_in_base(s, base, &caps);

	return (i);
}
