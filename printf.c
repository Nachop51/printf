#include "printf.h"
#include <stdio.h>

int _printf(char * format, ...)
{
	print_f print[] = {
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"c", print_char},
		{NULL, NULL}
	};
	int i = 0, j = 0, count = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (print[j].s[0])
			{
				if (print[j].s[0] == format[i + 1])
				{
					count += print[j].f(args);
					i++;
					break;
				}
				j++;
			}
			if (format[i + 1] != '\0')
			{
				i++;
				continue;
			}
			else
				break;
		}
		_stdout(format[i]);
		count++;
		i++;
	}
	va_end(args);
	return (count - 1);
}

int print_string(va_list args)
{
	int i = 0;

	char *str = va_arg(args, char *);
	while (str[i])
	{
		_stdout(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_number - prints an integer
 * @n: number to print
 */
int print_int(va_list args)
{
	int count = 0, var = 1, n = va_arg(args, int), count_char = 0;
	unsigned int out, test;

	if (n < 0)
	{
		_stdout('-');
		count_char++;
		out = n * -1;
	}
	else
		out = n;
	test = out;
	while (test != 0)
	{
		test /= 10;
		count++;
	}
	count--;
	while (count > 0)
	{
		var = power(10, count);
		_stdout((out / var) % 10 + '0');
		count_char++;
		count--;
	}
	_stdout(out % 10 + '0');
	count_char++;
	return (count_char);
}

int print_char(va_list args)
{
	_stdout(va_arg(args, int));
	return (1);
}

/**
 * power - sadsad
 * @a: first parameter
 * @b: second parameter
 *
 * Return: an integer
 */
int power(int a, int b)
{
	int result = 1;

	for (; b > 0; b--)
	{
		result = result * a;
	}
	return (result);
}
