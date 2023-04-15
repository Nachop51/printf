#include "main.h"

/**
 * _printf - copy of the actual function "printf"
 * @format: way to format the parameters and text
 * @...: n parameters
 *
 * Return: The amount of char printed
 */
int _printf(const char *format, ...)
{
	print_f print[] = {
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"c", print_char},
		{"%", print_percentage},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_heXadecimal},
		{"r", print_reversed},
		{"S", print_String},
		{"p", print_pointer},
		{"R", print_rot13},
		{"u", print_unsigned_int},
		{NULL, NULL}
	};
	int count = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	va_start(args, format);
	count = print_aux(format, print, args);
	va_end(args);
	return (count);
}
