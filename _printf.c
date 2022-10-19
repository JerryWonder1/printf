#include "main.h"

/**
 * _printf - copy of C's printf
 *
 * @format: the string to be printed to screen, may contain directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned long int i, length;
	char character, next_character;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	length = 0;

	for (i = 0; *(format + i); i++)
	{
		character = *(format + i);
		next_character = *(format + i + 1);
		if (character == '%')
		{
			print_substitution(&character, &next_character, args);

			i++;
		}
		else if (character == '\\')
		{
			length += print_special_char(&next_character, args);
			i++;
		}
		else
			length += _putchar(character);
	}

	va_end(args);

	return (length);
}
