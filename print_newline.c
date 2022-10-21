#include "main.h"

/**
 * print_newline - writes a newline character to a buffer
 *
 * @args: va_list object, but unused here
 * @buffer: the buffer to write to
 * Return: 1
 */
int print_newline(va_list __attribute__((__unused__)) args, char *buffer)
{
	add_to_buffer('\n', buffer);

	return (1);
}
