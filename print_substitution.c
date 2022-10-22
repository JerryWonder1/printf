#include "main.h"

/**
 * make_substitution - intepretes directives and calles the
 *                     appropraite function based on directive type
 *
 * @character: the character used to signify the directive ('%')
 * @next_character: the special character that follows the '%' symbol
 * @args: va_list object
 * @buffer: buffer to write to
 * Return: the length of characters printed to screen
 */
int make_substitution(char *character, char *next_character,
		      va_list args, char *buffer)
{
	unsigned long int j, length;
	function_map print_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", print_base2},
		{"o", print_base8},
		{"u", print_base10},
		{"x", print_in_basex},
		{"X", print_in_baseX},
		{"S", print_string_all},
		{"p", print_address},
		{NULL, NULL}
	};

	if (*next_character == '%')
	{
		add_to_buffer('%', buffer);
		return (1);
	}

	length = 0;

	for (j = 0; print_type[j].s; j++)
	{
		if (*(print_type[j].s) == *next_character)
		{
			length += print_type[j].f(args, buffer);
			break;
		}
	}

	if (print_type[j].s == NULL)
	{
		add_to_buffer(*character, buffer);
		add_to_buffer(*next_character, buffer);
		length += 2;
	}

	return (length);
}
