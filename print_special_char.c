#include "main.h"

/**
 * print_special_char - prints special characters like newline and the likes
 *
 * @next_character: the special character
 * @args: va_list object
 * Return: the length of characters printed to screen
 */
int print_special_char(char *next_character, va_list args)
{
	unsigned long int j, length;
	function_map print_type[] = {
		{"n", print_newline},
		{NULL, NULL}
	};

	length = 0;

	if (*next_character == '\\')
	{
		length += _putchar('\\');
		return (length);
	}

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
		length += _putchar('\\');
		length += _putchar(*next_character);
	}

	return (length);
}
