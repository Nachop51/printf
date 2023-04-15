#include "main.h"

/**
 * p_rot13 - print a string in rot13
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_rot13(buffer_t *buffer, va_list args)
{
	char *str = va_arg(args, char *);
	int i, j;

	if (!str)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (!_is_alpha(str[i]))
		{
			write_buffer(buffer, str[i]);
			continue;
		}
		if (str[i] > 'm' || (str[i] > 'M' && str[i] < 'a'))
			j = -13;
		else
			j = 13;
		write_buffer(buffer, str[i] + j);
	}
}

/**
 * p_reverse - print a string in reverse
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_reverse(buffer_t *buffer, va_list args)
{
	char *str = va_arg(args, char *);
	int i;

	if (!str)
	{
		write_buffer_str_n(buffer, "(null)", 6);
		return;
	}
	for (i = _strlen(str) - 1; i >= 0; i--)
		write_buffer(buffer, str[i]);
}

/**
 * p_pointer - print a pointer
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_pointer(buffer_t *buffer, va_list args)
{
	void *p = va_arg(args, void *);
	unsigned long int addr = (unsigned long int)p, len = 0;

	if (!p)
	{
		write_buffer_str_n(buffer, "(nil)", 6);
		return;
	}
	len = number_length(addr, 16, UNSIGNED, buffer->mod.precision);

	if (!(buffer->mod.flags & FLAG_MINUS))
		print_width(buffer, len + 2);
	write_buffer_str_n(buffer, "0x", 2);
	print_base_long(addr, "0123456789abcdef", 16, buffer);
	if (buffer->mod.flags & FLAG_MINUS)
		print_width(buffer, len + 2);
}

/**
 * p_string_ascii - print a string in ascii
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_string_ascii(buffer_t *buffer, va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
	{
		write_buffer_str_n(buffer, "(null)", 6);
		return;
	}
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			write_buffer(buffer, '\\'), write_buffer(buffer, 'x');
			if (str[i] < 16)
				write_buffer(buffer, '0');
			print_base(str[i], "0123456789ABCDEF", 16, buffer);
		}
		else
			write_buffer(buffer, str[i]);
		i++;
	}
}

/**
 * p_u_int - print an unsigned integer
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_u_int(buffer_t *buffer, va_list args)
{
	unsigned long long_n = 0;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, unsigned long);
	else
		long_n = va_arg(args, unsigned int);

	format_number(long_n, 10, buffer, LOWER, UNSIGNED);
}
