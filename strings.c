#include "main.h"

/**
 * _stdout - write a character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _stdout(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - return the length of a string
 * @s: string to measure
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _is_alpha - check if a character is alphabetic
 * @c: character to check
 *
 * Return: 1 if alphabetic, 0 otherwise
 */
int _is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 * Return: integer value of string
 */
int _atoi(const char *s)
{
	int i = 0, sign = 1, num = 0;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		num *= 10;
		num += (s[i] - '0');
		i++;
	}
	return (num * sign);
}

/**
 * number_length - get the length of a number
 * @n: number to get length of
 * @base_len: length of base
 * @is_u: 1 if unsigned, 0 otherwise
 * @precision: precision of number
 *
 * Return: length of number
 */
int number_length(long n, int base_len, int is_u, int precision)
{
	int len = 1;
	unsigned long un = n;

	if (n == 0 && precision == 0)
		return (0);
	if (n < 0 && !is_u)
		un = -n;

	/* len starts in 1 because if we have a number < base_len, we need to */
	/* count at least one digit */
	while (un / base_len)
	{
		un /= base_len;
		++len;
	}

	return (len);
}
