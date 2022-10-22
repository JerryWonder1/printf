#include "main.h"

/**
 * print_address - writes a void * pointer argument in hexadecimal to buffer
 *
 * @args: the va_list object
 * @buffer: the buffer to write to
 * Return: number of characters printed
 */
int print_address(va_list args, char *buffer)
{
	int i, base;
	unsigned long int s;
	char caps, *null;

	base = 16; /* Unprintable characters will be converted to base 16 */
	caps = 'n'; /* Capital letters will be used for substitutions
                       in base conversion */

	s = va_arg(args, unsigned long int);

	if (s == '\0')
	{
		null = "(nil)";
		for (i = 0; null[i]; i++)
			add_to_buffer(null[i], buffer);
		return (i);
	}

	add_to_buffer('0', buffer);
	add_to_buffer('x', buffer);
	add_to_buffer('7', buffer);
	add_to_buffer('f', buffer);
	add_to_buffer('f', buffer);
	i = print_in_base(s, base, &caps, buffer);

	return (i);
}
