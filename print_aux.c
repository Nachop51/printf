#include "printf.h"
#include <stdio.h>

/**
 * print_aux - auxiliar function of _printf
 * @format: text and ways to format the output
 * @print: struct of indetifiers and functions
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_aux(const char *format, print_f print[], va_list args)
{
	int i = 0, j = 0, count = 0;

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
	return (count);
}

/**
 * print_rot13 - traduces a string into rot13
 * @args: list of arguments
 *
 * Return: the amount of chars printed
 */
int print_rot13(va_list args)
{
	int i = 0, j = 0;
	char target[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char replace[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(args, char *);

	if (s == NULL)
		return (-1);
	while (s[i])
	{
		j = 0;
		while (target[j])
		{
			if (target[j] == s[i])
			{
				_stdout(replace[j]);
				break;
			}
			j++;
		}
		i++;
	}
}

/**
 * print_reversed - prints out a string reversed
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_reversed(va_list args)
{
	int i;
	char *s = va_arg(args, char *);

	while (s[i])
		i++;

	while (i--)
		_stdout(s[i]);
}
