#include "main.h"

/**
 * print_in_base - writes a number in base 'base' to a buffer
 *
 * @num: the number to be printed
 * @base: the base to convert number to
 * @caps: determines if number substitutions will be in capital case or not
 * @buffer: buffer to write to
 * Return: the number of characters printed
 */
int print_in_base(unsigned long int num, unsigned int base,
		  char *caps, char *buffer)
{
	unsigned int numerator, remainder;
	int length = 0;

	if (num >= base)
	{
		numerator = num / base;
		remainder = num % base;

		length += print_in_base(numerator, base, caps, buffer);

		add_to_buffer(substitute_number(remainder, caps), buffer);
	}
	else
		add_to_buffer(substitute_number(num, caps), buffer);
	length++;

	return (length);
}

/**
 * substitute_number - substitute a number to letters if greater than 10
 *                     else return the number in char form
 *
 * @num: the number to be transformed
 * @caps: a flag that determines whether to substitute with capital
 *        letters or not
 * Return: number in char form or number's substitution
 */
char substitute_number(int num, char *caps)
{
	char caps_subs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char subs[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char s;

	if (num > 9)
		s = *caps == 'y' ? caps_subs[num - 10] : subs[num - 10];
	else
		s = '0' + num;

	return (s);
}
