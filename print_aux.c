#include "main.h"

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
					if (format[i + 1] > 32 && format[i + 1] < 127)
					{
						count++, _stdout(format[i]);
						break;
					}
					else
						return (-1);
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
	int i = 0, count = 0;
	char *s = va_arg(args, char *);

	while (s[i])
	{
		if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
		{
			if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
			{
				_stdout(s[i] + 13);
				count++;
			}
			else
			{
				_stdout(s[i] - 13);
				count++;
			}
		}
		else
		{
			_stdout(s[i]);
			count++;
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
	int i = 0, j = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		i = _printf("(null)");
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_stdout('\\');
			_stdout('x');
			if (str[i] < 16)
				_stdout('0');
			print_heXadecimaln(str[i]);
			j += 4;
		}
		else
		{
			_stdout(str[i]);
			j++;
		}
	}
	return (j);
}

/**
 * print_heXadecimaln - converts a number into hexadecimal with upper letters
 * @n: takes an integer instead of a list
 *
 * Return: amount of chars printed
 */
int print_heXadecimaln(unsigned int n)
{
	unsigned int i = 0, j = 0, a = n;
	char *s;

	while (a != 0)
		j++, a /= 16;
	s = malloc(sizeof(char) * j + 1);
	if (!n)
	{
		_stdout('0');
		return (1);
	}
	while (n > 0)
	{
		if (n % 16 >= 10)
			s[i] = ((n % 16) - 10) + 65;
		else
		{
			s[i] = n % 16 + 48;
		}
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
