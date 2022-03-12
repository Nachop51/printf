#include "printf.h"
#include <stdio.h>

int print_percentage(__attribute__((unused))va_list args)
{
	_stdout('%');
	return (1);
}

int print_binary(va_list args)
{
	int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

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

int print_octal(va_list args)
{
	int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

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

int print_hexadecimal(va_list args)
{
	int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

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
		if (n % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
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

int print_heXadecimal(va_list args)
{
	int n = va_arg(args, unsigned int), i = 0, j = 0, a = n;
	char *s;

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
		if (n % 16 == 0)
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