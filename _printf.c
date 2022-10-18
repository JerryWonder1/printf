#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i, j, length;
	char character, next_character;
	function_map print_type1[] = {
		{"c", print_char},
		{"s", print_string},
		{"n", print_newline},
		{NULL, NULL}
	};
	function_map print_type2[] = {
		{"n", print_newline},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	length = 0;

	for (i = 0; *(format + i); i++)
	{
		character = *(format + i);
		next_character = *(format + i + 1);
		if (character == '%' && next_character == '%')
		{
			length += _putchar(next_character);
			i++;
		}
		else if (character == '%')
		{
		        for (j = 0; print_type1[j].s; j++)
			{
				if (*(print_type1[j].s) == next_character)
				{
					length += print_type1[j].f(args);
					break;
				}
			}

			if (print_type1[j].s == NULL)
			{
				length += _putchar(character);
				length += _putchar(next_character);
			}

			i++;
		}
		else if (character == '\\')
		{
			for (j = 0; print_type2[j].s; j++)
			{
				if (*(print_type2[j].s) == next_character)
				{
					length += print_type2[j].f(args);
					break;
				}
			}
/*
			if (print_type2[j].s == NULL)
				length += _putchar(next_character);
*/
			i++;
		}
		else
			length += _putchar(character);
	}

	va_end(args);

	return (length);
}
