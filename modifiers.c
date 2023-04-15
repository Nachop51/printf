#include "main.h"

/**
 * reset_modifiers - reset modifiers
 * @buffer: buffer to reset
 */
void reset_modifiers(buffer_t *buffer)
{
	buffer->mod.flags = 0;
	buffer->mod.width = 0;
	buffer->mod.precision = -1; /* -1 means no precision */
	buffer->mod.length = 0;
}

/**
 * is_flag - Checks if a character is a flag
 * @format: Format string
 * @buffer: Buffer to evaluate
 *
 * Return: 1 if flag, 0 if not
 */
int is_flag(const char *format, buffer_t *buffer)
{
	int i = 0, j = 0, found_flag = 1, total_flags = 0;
	char *flags = "-0+ #";

	if (buffer->mod.width != 0 ||
		buffer->mod.precision != -1 ||
		buffer->mod.length != 0)
		return (0);

	for (i = 0; format[i] && found_flag; i++)
	{
		found_flag = 0;
		for (j = 0; flags[j]; j++)
		{
			if (format[i] == flags[j])
			{
				buffer->mod.flags |= 1 << j;
				found_flag = 1, total_flags++;
				break;
			}
		}
	}
	return (total_flags);
}

/**
 * calculate_width - Calculates the width of a format string
 * @format: Format string
 * @buffer: Buffer to evaluate
 * @args: Arguments to format string
 *
 * Return: How much to increment i in
 * _printf_helper, or 0 on error
 */
int calculate_width(const char *format, buffer_t *buffer, va_list args)
{
	int i = 0;

	if (buffer->mod.precision != -1 ||
		buffer->mod.length != 0)
		return (0);

	if (format[i] == '*')
	{
		buffer->mod.width = va_arg(args, int);
		if (buffer->mod.width < 0)
			buffer->mod.width = 0;
		return (1);
	}

	buffer->mod.width = _atoi(format + i);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	return (i);
}

/**
 * calculate_precision - Calculates the precision of a format string
 * @format: Format string
 * @buffer: Buffer to evaluate
 * @args: Arguments to format string
 *
 * Return: How much to increment i in
 * _printf_helper, or 0 on error
 */
int calculate_precision(const char *format, buffer_t *buffer, va_list args)
{
	int i = 1; /* 1 for the '.' */

	if (buffer->mod.length != 0)
		return (0);

	if (format[i] == '*')
	{
		buffer->mod.precision = va_arg(args, int);
		if (buffer->mod.precision < 0)
			buffer->mod.precision = 0;
		return (i + 1); /* 1 for the '*' */
	}

	buffer->mod.precision = _atoi(format + i);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	return (i);
}

/**
 * is_length - Checks if a character is a length
 * @c: Character to check
 * @buffer: Buffer to evaluate
 *
 * Return: 1 if length, 0 if not
 */
int is_length(char c, buffer_t *buffer)
{
	char *lengths = "hl";
	int i = 0;

	for (; lengths[i]; i++)
	{
		if (c == lengths[i])
		{
			buffer->mod.length |= 1 << i;
			return (1);
		}
	}
	return (0);
}
