#include "main.h"

/**
 * initialize_buffer - sets all elements of the buffer to the null terminator
 *
 * @buffer: the buffer to be initialized
 */
void initialize_buffer(char *buffer)
{
	size_t i;

	for (i = 0; i < BUFFSIZE; i++)
		buffer[i] = '\0';
}

/**
 * add_to_buffer - adds a character to a buffer
 *
 * @x: the character to be added to the buffer
 * @buffer: the buffer to which character is added to
 */
void add_to_buffer(char x, char *buffer)
{
	int index = 0;

	while (buffer[index])
		index++;

	if (index < BUFFSIZE)
		buffer[index] = x;
}

/**
 * buffsize - returns the length of buffer
 *
 * @buffer: the buffer to be processed
 * Return: the length of the buffer
 */
size_t buffsize(char *buffer)
{
	size_t length = 0;

	while (buffer[length])
		length++;

	return (length);
}

/**
 * print_buffer - prints a buffer
 *
 * @buffer: the buffer to be printed
 * Return: the number of bytes written on success or -1 on failure
 */
int print_buffer(char *buffer)
{
	int length = buffsize(buffer);

	return (write(1, buffer, length));
}
