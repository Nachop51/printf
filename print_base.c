#include "main.h"

/**
 * print_base_short - print a number in a given base
 * @n: number to print
 * @base: base to print in
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_base_short(unsigned short int n, char *base,
					  int base_len, buffer_t *buffer)
{
	if (n / base_len)
		print_base_short(n / base_len, base, base_len, buffer);
	write_buffer(buffer, base[n % base_len]);
}

/**
 * print_base - print a number in a given base
 * @n: number to print
 * @base: base to print in
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_base(unsigned int n, char *base, int base_len, buffer_t *buffer)
{
	if (n / base_len)
		print_base(n / base_len, base, base_len, buffer);
	write_buffer(buffer, base[n % base_len]);
}

/**
 * print_base_long - print a number in a given base
 * @n: number to print
 * @base: base to print in
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_base_long(unsigned long n, char *base,
					 int base_len, buffer_t *buffer)
{
	if (n / base_len)
		print_base_long(n / base_len, base, base_len, buffer);
	write_buffer(buffer, base[n % base_len]);
}

/**
 * print_symbol - print a symbol for a number
 * @n: number to print symbol for
 * @buffer: buffer to write to
 * @is_u: 1 if unsigned, 0 otherwise
 */
void print_symbol(long n, buffer_t *buffer, int is_u)
{
	if (!is_u && n < 0)
		write_buffer(buffer, '-');
	else if (buffer->mod.flags & FLAG_PLUS)
		write_buffer(buffer, '+');
	else if (buffer->mod.flags & FLAG_SPACE)
		write_buffer(buffer, ' ');
}

/**
 * print_string - print a string
 * @str: string to print
 * @buffer: buffer to write to
 * @is_ch: 1 if character, 0 otherwise
 */
void print_string(char *str, buffer_t *buffer, char is_ch)
{
	int len = 0;

	if (!is_ch)
	{
		if (buffer->mod.precision == 0)
			return;
		if (buffer->mod.precision == -1)
			len = _strlen(str);
		else
			len = buffer->mod.precision;
	}
	else
		len = 1;

	if (!(buffer->mod.flags & FLAG_MINUS))
		print_width(buffer, len);
	write_buffer_str_n(buffer, str, len);
	if (buffer->mod.flags & FLAG_MINUS)
		print_width(buffer, len);
}
