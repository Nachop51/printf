#include "main.h"

/**
 * _printf - Prints a formatted string to the standard output
 * @format: Format string
 * @...: Arguments to format string
 *
 * Return: Number of characters printed or -1 on error
 */
int _printf(const char *format, ...)
{
	int ret = 0;
	va_list args;
	print_t p[] = {
		{'s', p_str},
		{'c', p_char},
		{'d', p_int},
		{'i', p_int},
		{'u', p_u_int},
		{'%', p_percent},
		{'b', p_binary},
		{'o', p_octal},
		{'x', p_hex},
		{'X', p_hex_upper},
		{'p', p_pointer},
		{'r', p_reverse},
		{'S', p_string_ascii},
		{'R', p_rot13},
		{'\0', NULL}};
	buffer_t buffer = {0};

	if (!format)
		return (-1);

	init_buffer(&buffer);
	va_start(args, format);
	ret = _printf_helper(format, p, &buffer, args);
	va_end(args);
	if (ret == -1)
		return (ret);

	flush_buffer(&buffer);
	return (buffer.counter);
}

/**
 * _printf_helper - Print a formatted string to stdout
 * @format: Format string
 * @p: Array of print_t structs
 * @buffer: Buffer to write to
 * @args: Arguments to format string
 *
 * Return: Number of characters printed
 */
int _printf_helper(const char *format, print_t p[],
				   buffer_t *buffer, va_list args)
{
	int i = 0, ret = 0;

	while (format[i])
	{
		if (format[i] != '%')
		{
			i += write_buffer(buffer, format[i]);
			continue;
		}
		ret = to_format(format + i, p, buffer, args);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	return (ret);
}

/**
 * to_format - Print a formatted string to stdout
 * @format: Format string
 * @p: Array of print_t structs
 * @buffer: Buffer to write to
 * @args: Arguments to format string
 *
 * Return: How much to increment i in
 * _printf_helper, or -1 on error
 */
int to_format(const char *format, print_t p[], buffer_t *buffer, va_list args)
{
	int i = 1; /* 0 -> '%' */
	void (*func)(buffer_t *, va_list);

	reset_modifiers(buffer);

	i += is_flag(format + i, buffer);
	if ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
		i += calculate_width(format + i, buffer, args);
	if (format[i] == '.')
		i += calculate_precision(format + i, buffer, args);
	i += is_length(format[i], buffer);

	if (format[i] == '\0')
		return (-1);

	func = eval_specifier(format[i], p);
	if (func)
	{
		func(buffer, args);
		/* i + 1 this +1 is the specifier itself */
		return (i + 1);
	}
	/* Sum the specifier */
	return (evaluate_modifiers(buffer, format, i + 1));
}

/**
 * eval_specifier - Print a formatted string to stdout
 * @specifier: Specifier to evaluate
 * @p: Array of print_t structs
 *
 * Return: 1 on success, 0 on failure
 */
void (*eval_specifier(char specifier, print_t p[]))(buffer_t *, va_list)
{
	int i = 0;

	while (p[i].type)
	{
		if (p[i].type == specifier)
			return (p[i].f);
		i++;
	}
	return (0);
}

/**
 * evaluate_modifiers - Print a formatted string to stdout
 * @buffer: Buffer to write to
 * @format: Format string
 * @len: Length of format string
 *
 * Return: 1 on success, 0 on failure
 */
int evaluate_modifiers(buffer_t *buffer, const char *format, int len)
{
	int i = 0;

	for (; i < len; i++)
	{
		if (format[i] == ' ' || format[i] == '+')
		{
			while (format[i] == ' ' || format[i] == '+')
				i++;
			i--;
			write_buffer(buffer, ' ');
			continue;
		}
		if (format[i] == '.')
		{
			++i, write_buffer(buffer, '.');
			write_buffer_int(buffer, buffer->mod.precision);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			i--;
			continue;
		}
		if (format[i] == 'h' || format[i] == 'l')
			continue;
		write_buffer(buffer, format[i]);
	}
	return (i);
}
