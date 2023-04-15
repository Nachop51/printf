#include "main.h"

/**
 * init_buffer - initialize a buffer
 * @buffer: buffer to initialize
 */
void init_buffer(buffer_t *buffer)
{
	int i = 0;
	mod_t mod = {0, 0, -1, 0};
	/* flags, width, precision, length */

	buffer->i = 0;
	buffer->counter = 0;
	while (i < BUFFER_SIZE)
		buffer->buf[i++] = '\0';
	buffer->mod = mod;
}

/**
 * flush_buffer - flush a buffer
 * @buffer: buffer to flush
 * Return: number of characters printed
 */
void flush_buffer(buffer_t *buffer)
{
	int i = 0;

	write(1, buffer->buf, buffer->i);
	while (i < buffer->i)
		buffer->buf[i++] = '\0';
	buffer->i = 0;
}

/**
 * write_buffer - write a character to a buffer
 * @buffer: buffer to write to
 * @c: character to write
 * Return: number of characters printed
 */
int write_buffer(buffer_t *buffer, char c)
{
	if (buffer->i == BUFFER_SIZE)
		flush_buffer(buffer);
	buffer->buf[buffer->i++] = c;
	buffer->counter++;
	return (1);
}

/**
 * write_buffer_str_n - write a string to a buffer
 * @buffer: buffer to write to
 * @str: string to write
 * @n: number of characters to write
 * Return: number of characters printed
 */
int write_buffer_str_n(buffer_t *buffer, char *str, int n)
{
	int i = 0;

	do
		write_buffer(buffer, str[i++]);
	while (str[i] && i < n);
	return (i);
}

/**
 * write_buffer_int - Writes an integer to a buffer
 * @buffer: buffer to write to
 * @n: Number to write
 *
 * Return: Number of characters printed
 */
int write_buffer_int(buffer_t *buffer, int n)
{
	int i = 1;

	if (n / 10)
		i += write_buffer_int(buffer, n / 10);
	write_buffer(buffer, n % 10 + '0');
	return (i);
}
