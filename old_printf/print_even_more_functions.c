#include "main.h"

/**
 * print_pointer - prints out the address of a pointer in memory
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_pointer(va_list args)
{
	long int i = 0, j = 0;
	char *str = "(nil)";
	void *p = va_arg(args, void*);

	if (!p)
	{
		while (str[i])
		{
			_stdout(str[i]);
			i++;
		}
		return (i);
	}
	i = (unsigned long int)p;
	_stdout('0');
	_stdout('x');
	j += print_hexadecimal_aux(i);
	return (j + 2);
}

/**
 * print_hexadecimal_aux - auxiliar function to print a pointer
 * @n: the address of the pointer
 *
 * Return: amount of chars printed
 */
int print_hexadecimal_aux(unsigned long int n)
{
	long int i = 0, j = 0, *ar;
	unsigned long int a = n;

	if (!n)
	{
		_stdout('0');
		return (1);
	}
	while (a / 16 != 0)
	{
		a /= 16;
		j++;
	}
	j++;
	ar = malloc(sizeof(long int) * j);
	if (ar == NULL)
		return (-1);
	while (i < j)
	{
		ar[i] = n % 16;
		n /= 16;
		i++;
	}
	i = j - 1;
	while (i >= 0)
	{
		if (ar[i] > 9)
			ar[i] += 39;
		_stdout(ar[i] + '0');
		i--;
	}
	free(ar);
	return (j);
}
