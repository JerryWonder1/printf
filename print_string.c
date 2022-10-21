#include "main.h"

/**
 * print_string - writes a string from a va_list object type to a buffer
 *
 * @args: the va_list object
 * @buffer: the buffer to write to
 * Return: number of characters printed
 */
int print_string(va_list args, char *buffer)
{
	int i;
	char *s;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i]; i++)
		add_to_buffer(s[i], buffer);

	return (i);
}

/**
 * print_string_all - writes a string from a va_list object type to a buffer
 *                    Non printable characters (0 < ASCII value < 32 or >= 127)
 *                    are printed this way: \x, followed by the ASCII code value
 *                    in hexadecimal
 *
 * @args: the va_list object
 * @buffer: the buffer to write to
 * Return: number of characters printed
 */
int print_string_all(va_list args, char *buffer)
{
	int i, base;
	char *s, caps;

	base = 16; /* Unprintable characters will be converted to base 16 */
	caps = 'y'; /* Capital letters will be used for substitutions
                       in base conversion */

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
		        add_to_buffer('\\', buffer);
			add_to_buffer('x', buffer);
			printf("%d", s[i]);
			if (s[i] < base)
				add_to_buffer('0', buffer);
			print_in_base(s[i], base, &caps, buffer);
		}
		else
			add_to_buffer(s[i], buffer);
	}

	return (i);
}
