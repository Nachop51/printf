#include "main.h"

/**
 * p_binary - print a number in binary
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_binary(buffer_t *buffer, va_list args)
{
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		long_n = va_arg(args, unsigned int);

	if (long_n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer_str_n(buffer, "0b", 2);

	format_number(long_n, 2, buffer, LOWER, UNSIGNED);
}

/**
 * p_octal - print a number in octal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_octal(buffer_t *buffer, va_list args)
{
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		long_n = va_arg(args, unsigned int);

	if (long_n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer(buffer, '0');

	format_number(long_n, 8, buffer, LOWER, UNSIGNED);
}

/**
 * p_hex - print a number in hexadecimal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_hex(buffer_t *buffer, va_list args)
{
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		long_n = va_arg(args, unsigned int);

	if (long_n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer_str_n(buffer, "0x", 2);

	format_number(long_n, 16, buffer, LOWER, UNSIGNED);
}

/**
 * p_hex_upper - print a number in hexadecimal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_hex_upper(buffer_t *buffer, va_list args)
{
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		long_n = va_arg(args, unsigned int);

	if (long_n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer_str_n(buffer, "0X", 2);

	format_number(long_n, 16, buffer, UPPER, UNSIGNED);
}
