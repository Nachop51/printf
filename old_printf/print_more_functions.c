#include "main.h"

/**
 * print_percentage - prints out a percetange
 * @args: list of arguments
 *
 * Return: the number of char printed (1)
 */
int print_percentage(__attribute__((unused))va_list args)
{
	_stdout('%');
	return (1);
}

/**
 * print_binary - converts a number into binary
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

	if (!n)
	{
		_stdout('0');
		return (1);
	}
	while (a != 0)
	{
		a /= 2;
		j++;
	}
	s = malloc(sizeof(char) * j + 1);
	if (s == NULL)
		return (-1);

	while (n > 0)
	{
		if (n % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
		n /= 2;
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

/**
 * print_octal - converts a number into octal base
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

	if (!n)
	{
		_stdout('0');
		return (1);
	}
	while (a != 0)
	{
		a /= 8;
		j++;
	}
	s = malloc(sizeof(char) * j + 1);
	if (s == NULL)
		return (-1);
	while (n > 0)
	{
		s[i] = n % 8 + 48;
		n /= 8;
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

/**
 * print_hexadecimal - converts a number into hexadecimal with lower letters
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_hexadecimal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

	if (!n)
	{
		_stdout('0');
		return (1);
	}
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
			s[i] = ((n % 16) - 10) + 97;
		}
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

/**
 * print_heXadecimal - converts a number into hexadecimal with upper letters
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_heXadecimal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

	if (!n)
	{
		_stdout('0');
		return (1);
	}
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
