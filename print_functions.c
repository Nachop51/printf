#include "main.h"

/**
 * print_string - prints out a string
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_string(va_list args)
{
	char *str;
	unsigned int i = 0;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		_stdout(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_int - prints an integer
 * @args: number to print
 *
 * Return: amount of chars printed
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

/**
 * print_unsigned_int - prints out an unsigned integer
 * @args: number to print
 *
 * Return: amount of chars printed
 */
int print_unsigned_int(va_list args)
{
	unsigned int count = 0, var = 1, n = va_arg(args, unsigned int);
	unsigned int test = n, count_char = 0;

	if (!n)
	{
		_stdout('0');
		return (1);
	}
	while (test != 0)
	{
		test /= 10;
		count++;
	}
	count--;
	while (count > 0)
	{
		var = power(10, count);
		_stdout((n / var) % 10 + '0');
		count_char++;
		count--;
	}
	_stdout(n % 10 + '0');
	count_char++;
	return (count_char);
}

/**
 * print_char - prints out a char
 * @args: char to print
 *
 * Return: amount of chars printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_stdout(c);
	return (1);
}

/**
 * power - elevates a to the power of b
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
