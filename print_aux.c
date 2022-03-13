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

	if (s == NULL)
		return (-1);
	while (s[i])
		i++;

	while (i--)
		_stdout(s[i]);
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
		if (str[i] > 32 && str[i] <= 127)
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
int print_heXadecimaln(int n)
{
	unsigned int i = 0, j = 0, a = n;
	char *s, temp;

	if (!n)
		return (-1);
	while (a != 0)
	{
		a /= 16;
		j++;
	}
	s = malloc(sizeof(char) * j + 1);
	if (s == NULL)
		return (-1);

	while (n > 0)
	{
		if (n % 16 >= 10)
		{
			s[i] = ((n % 16) - 10) + 65;
		}
		else
			s[i] = n % 16 + 48;
		n /= 16;
		i++;
	}
	s[i] = '\0';
	j = 0;
	while (i != 0)
	{
		i--;
		_stdout(s[i]);
		j++;
	}
	free(s);
	return (j);
}
