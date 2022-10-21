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
