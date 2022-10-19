#include "main.h"

/**
 * print_substitution - intepretes directives and prints the appropraite
 *                      passed to the function
 *
 * @character: the character used to signify the directive ('%')
 * @next_character: the special character that follows the '%' symbol
 * @args: va_list object
 * Return: the length of characters printed to screen
 */
int print_substitution(char *character, char *next_character, va_list args)
{
	unsigned long int j, length;
	function_map print_type[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", print_base2},
		{"o", print_base8},
		{"u", print_int},
		{"x", print_in_basex},
		{"X", print_in_baseX},
		{NULL, NULL}
	};

	if (*next_character == '%')
		return (_putchar('%'));

	length = 0;

	for (j = 0; print_type[j].s; j++)
	{
		if (*(print_type[j].s) == *next_character)
		{
			length += print_type[j].f(args);
			break;
		}
	}

	if (print_type[j].s == NULL)
	{
		length += _putchar(*character);
		length += _putchar(*next_character);
	}

	return (length);
}
