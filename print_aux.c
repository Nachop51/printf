#include "main.h"
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
				if (print[j + 1].s == NULL)
				{
					_stdout('%');
					if (format[i + 1] != '\0')
						_stdout(format[i + 1]);
					count += 2;
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
	int i = 0, j = 0, count = 0;
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
				count++;
				break;
			}
			j++;
		}
		i++;
	}
	return (count);
}

/**
 * print_reversed - prints out a string reversed
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_reversed(va_list args)
{
	int i = 0, j = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
		return (-1);
	while (s[i])
		i++;

	while (i--)
		j++, _stdout(s[i]);
	return (j);
}

/**
 * print_String - prints out a string in the range of 33 and 127
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_String(va_list args)
{
	int i = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] > 32)
		{
			_stdout(str[i]);
		}
		else
		{
			_stdout('\\');
			_stdout('x');
			i += 2;
			i += print_heXadecimaln(str[i]);
		}
		i++;
	}
	return (i);
}

/**
 * print_heXadecimaln - converts a number into hexadecimal with upper letters
 * @n: takes an n 
 *
 * Return: amount of chars printed
 */
int print_heXadecimaln(unsigned int n)
{
	int i = 0;
	char *s;

	s = malloc(sizeof(char) * 3);
	if (!s)
		return (-1);

	s[0] = n / 10;
	s[1] = n % 10;
	s[2] = '\0';

	while (s[i])
		_stdout(s[i] + 48), i++;
	return (2);
}
