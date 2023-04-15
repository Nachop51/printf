#include "main.h"

/**
 * print_width - print the width
 * @buffer: buffer to write to
 * @length: Length of the object
 *
 * Return: 1 if number has a sign, 0 otherwise
 */
void print_width(buffer_t *buffer, int length)
{
	int i = 0;
	char c = buffer->mod.flags & FLAG_ZERO ? '0' : ' ';

	if (buffer->mod.flags & FLAG_ZERO && buffer->mod.precision > 0)
		c = ' ';

	if (buffer->mod.width > length)
		while (i++ < buffer->mod.width - length)
			write_buffer(buffer, c);
}

/**
 * print_precision - print the precision
 * @buffer: buffer to write to
 * @length: Length of the object
 */
void print_precision(buffer_t *buffer, int length)
{
	int i = 0;

	if (buffer->mod.precision > length)
	{
		for (i = 0; i < buffer->mod.precision - length; i++)
			write_buffer(buffer, '0');
	}
}

/**
 * format_number - Format a number
 * @num: number to format
 * @base: base of the number
 * @buffer: buffer to write to
 * @upper: 1 if uppercase, 0 otherwise
 * @is_u: 1 if unsigned, 0 otherwise
 */
void format_number(long num, int base, buffer_t *buffer, int upper, int is_u)
{
	int n_len = 0, old_len = 0;

	n_len = number_length(num, base, is_u, buffer->mod.precision);
	old_len = n_len;

	if (buffer->mod.precision > n_len)
		n_len = buffer->mod.precision;

	n_len += has_sign(num, buffer, is_u);

	if (buffer->mod.flags & FLAG_ZERO)
		print_symbol(num, buffer, is_u);

	if (!(buffer->mod.flags & FLAG_MINUS))
		print_width(buffer, n_len);

	if (!(buffer->mod.flags & FLAG_ZERO))
		print_symbol(num, buffer, is_u);

	/* print the precision using the old length */
	print_precision(buffer, old_len);

	if (!is_u)
		num = num < 0 ? -num : num;
	print_number(num, base, buffer, upper);
	if (buffer->mod.flags & FLAG_MINUS)
		print_width(buffer, n_len);
}

/**
 * print_number - print a number in a given base
 * @num: number to print
 * @base_len: length of base
 * @buffer: buffer to write to
 * @upper: 1 if uppercase, 0 otherwise
 */
void print_number(unsigned long num, int base_len, buffer_t *buffer, int upper)
{
	char *base = BASE_16;

	if (upper)
		base = BASE_16_UPPER;

	if (buffer->mod.precision == 0 && num == 0)
		return;

	if (buffer->mod.length & LENGTH_L)
		print_base_long(num, base, base_len, buffer);
	else if (buffer->mod.length & LENGTH_H)
		print_base_short(num, base, base_len, buffer);
	else
		print_base(num, base, base_len, buffer);
}

/**
 * has_sign - Determine if a number has a sign
 * @n: number to check
 * @buffer: buffer to write to
 * @is_u: 1 if unsigned, 0 otherwise
 *
 * Return: 1 if number has a sign, 0 otherwise
 */
int has_sign(long int n, buffer_t *buffer, int is_u)
{
	char sign = 0;

	if (is_u)
	{
		if (buffer->mod.flags & FLAG_PLUS)
			++sign;
		else if (buffer->mod.flags & FLAG_SPACE)
			++sign;
	}
	else
	{
		if (n >= 0)
		{
			if (buffer->mod.flags & FLAG_PLUS)
				++sign;
			else if (buffer->mod.flags & FLAG_SPACE)
				++sign;
		}
		else
			++sign;
	}
	return (sign);
}
